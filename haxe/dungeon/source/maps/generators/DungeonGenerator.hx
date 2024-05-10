package maps.generators;

import maps.generators.bsp.BSPNode;
import maps.generators.rooms.RectangularRoom;
import maps.scheme.MapScheme;
import maps.scheme.LayerScheme;
import maps.generators.rooms.BaseRoom;

@:enum abstract DungeonLayer(Int)
{
	var Background = 0;
	var Foregound = 1;
	var Collision = 2;
}

class DungeonGenerator extends BaseGenerator
{
	public function new()
	{
		mapScheme = null;
		root = null;
		rooms = new Array<BaseRoom>();
	}

	override public function generate(/* pass map config here */):MapScheme
	{
		// TODO Destroy old objects first

		this.mapScheme = new MapScheme(100, 100);

		var backgroundLayer = new LayerScheme(mapScheme);
		var foregoundLayer = new LayerScheme(mapScheme);
		var collisionLayer = new LayerScheme(mapScheme);
		mapScheme.layers.push(backgroundLayer);
		mapScheme.layers.push(foregoundLayer);
		mapScheme.layers.push(collisionLayer);

		root = new BSPNode();
		root.x = root.y = 0;
		root.width = mapScheme.width;
		root.height = mapScheme.height;

		splitNode(root, 5); // TODO Alter interations in a config constant

		mapScheme.node = root;
		mapScheme.rooms = rooms;

		return mapScheme;
	}

	private function splitNode(node:BSPNode, iteration:Int)
	{
		// TODO Alter to a configuration constant
		var minSize = 10;

		iteration--;

		generateRandomSplit(node, minSize);

		if (node.splitDirection == SplitDirection.None ||
			iteration == 0)
		{
			generateRoom(node);
			return;
		}

		var child1 = new BSPNode(node);
		var child2 = new BSPNode(node);

		var splitPoint = getSplitPoint(node.splitDimension, minSize);

		if (node.splitDirection == SplitDirection.Horizontal)
		{
			child1.x = node.x;
			child1.y = node.y;
			child1.width = node.width;
			child1.height = splitPoint;

			child2.x = node.x;
			child2.y = node.y + splitPoint;
			child2.width = node.width;
			child2.height = node.height - splitPoint;
		}
		else if (node.splitDirection == SplitDirection.Vertical)
		{
			child1.x = node.x;
			child1.y = node.y;
			child1.width = splitPoint;
			child1.height = node.height;

			child2.x = node.x + splitPoint;
			child2.y = node.y;
			child2.width = node.width - splitPoint;
			child2.height = node.height;
		}

		node.children.push(child1);
		node.children.push(child2);

		if (iteration != 0)
		{
			splitNode(child1, iteration);
			splitNode(child2, iteration);
		}
	}

	function generateRoom(node:BSPNode)
	{
		var room = new RectangularRoom();
		room.generate(node.x, node.y, node.width, node.height);
		rooms.push(room);
	}

	private function generateRandomSplit(node:BSPNode, minSize:Int):Void
	{
		var all = [SplitDirection.Horizontal, SplitDirection.Vertical];
		shuffleArray(all);

		while (all.length > 0)
		{
			node.splitDirection = all.pop();

			if (node.splitDimension >= 2 * minSize)
				return;
		}

		node.splitDirection = SplitDirection.None;
	}

	private function getSplitPoint(value:Int, minSize:Int):Int
	{
		return Std.random(value - 2 * minSize) + minSize;
	}

	public function shuffleArray<T>(array:Array<T>):Void
	{
		var tmp:T;
		var j:Int;
		var i:Int = array.length;

		while (i > 0)
		{
			j = Std.random(i);
			tmp = array[--i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
}

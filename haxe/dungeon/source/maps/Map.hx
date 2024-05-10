package maps;

import flixel.FlxSprite;
import flixel.group.FlxGroup;
import flixel.tile.FlxTilemap;
import maps.generators.bsp.BSPNode;
import maps.generators.rooms.BaseRoom;
import maps.scheme.MapScheme;

class Map extends FlxGroup
{
	public var width:Int;
	public var height:Int;

	private var _scheme:MapScheme;

	public function new()
	{
		super();
	}

	public function loadMapData(scheme:MapScheme)
	{
		_scheme = scheme;

		for(layer in scheme.layers)
		{
			var tilemap = new FlxTilemap();

			tilemap.widthInTiles = scheme.width;
			tilemap.heightInTiles = scheme.height;
			tilemap.loadMap(layer.tileArray, "assets/images/auto_tiles.png", 16, 16, 0, 1, 1, 1);
			add(tilemap);
		}

		var sprite = new FlxSprite();
		sprite.makeGraphic(300, 300, 0xffffffff);
		sprite.x = sprite.y = 0;
		add(sprite);

		navigateNodes(scheme.node);
		navigateRooms(scheme.rooms);
	}

	private function navigateNodes(node:BSPNode)
	{
		if (node.children.length == 0)
		{
			var sprite = new FlxSprite();

			var red = Std.random(256);
			var green = Std.random(256);
			var blue = Std.random(256);
			var color = 0xff000000 +
				0x00010000 * red +
				0x00000100 * green +
				0x00000001 * blue;

			sprite.makeGraphic(node.width * 3, node.height * 3, color);
			sprite.x = node.x * 3.0;
			sprite.y = node.y * 3.0;

			add(sprite);
		}
		else
		{
			for (item in node.children)
				navigateNodes(item);
		}
	}

	private function navigateRooms(rooms:Array<BaseRoom>)
	{
		for (room in rooms)
		{
			var sprite = new FlxSprite();

			sprite.makeGraphic(room.width * 3, room.height * 3, 0xff000000);
			sprite.x = room.x * 3;
			sprite.y = room.y * 3;

			add(sprite);
		}
	}
}

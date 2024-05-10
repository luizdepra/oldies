package maps.scheme;

import maps.generators.rooms.BaseRoom;
import maps.generators.bsp.BSPNode;
import maps.scheme.MapScheme;

class MapScheme
{
	public var width(default, null):Int;
	public var height(default, null):Int;

	public var layers(default, null):Array<LayerScheme>;

	public var node:BSPNode; // TODO Remove
	public var rooms:Array<BaseRoom>; // TODO Remove

	public function new(width:Int, height:Int)
	{
		this.width = width;
		this.height = height;

		layers = new Array<LayerScheme>();
	}
}

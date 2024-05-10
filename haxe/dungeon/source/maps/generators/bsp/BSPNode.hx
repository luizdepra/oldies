package maps.generators.bsp;

import flixel.util.FlxRect;

enum SplitDirection
{
	None;
	Vertical;
	Horizontal;
}

class BSPNode
{
	public var x:Int;
	public var y:Int;

	public var width:Int;
	public var height:Int;

	public var splitDirection:SplitDirection;
	public var splitDimension(get, null):Int;
	
	public var parent(default, null):BSPNode;
	public var children(default, null):Array<BSPNode>;

	public function new(parent:BSPNode = null)
	{
		this.parent = parent;
		this.children = new Array<BSPNode>();
	}
	
	public inline function get_splitDimension():Int
	{
		return splitDirection == SplitDirection.Vertical ? width :
			   splitDirection == SplitDirection.Horizontal ? height :
				   0;
	}
}

package maps.generators.rooms;

/**
 * ...
 * @author ...
 */
class BaseRoom
{
	public var x(default, null):Int;
	public var y(default, null):Int;
	
	public var width(default, null):Int;
	public var height(default, null):Int;
	
	public function generate(minX:Int, minY:Int, maxWidth:Int, maxHeight:Int):Void
	{
	}
}

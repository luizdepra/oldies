package maps.generators.rooms;

/**
 * ...
 * @author Luiz F. A. de Prá
 */
class RectangularRoom extends BaseRoom
{
	public function new() 
	{
	}
	
	override public function generate(minX:Int, minY:Int, maxWidth:Int, maxHeight:Int):Void
	{
		var minSize = 10; // TODO put it on a config file
		
		width = Std.random(maxWidth - minSize) + minSize;
		height = Std.random(maxHeight - minSize) + minSize;
		
		x = minX + Std.random(maxWidth - width);
		y = minY + Std.random(maxHeight - height);
	}
}
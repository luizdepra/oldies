package map 
{
	import org.flixel.*;
	/**
	 * Room - Room informations
	 * @author Luiz F. A. de Prá
	 */
	public class Room extends FlxRect
	{
		public static const TYPE_CORRIDOR:int			= 0;
		public static const TYPE_SQUARE_ROOM:int		= 1;
		
		public var type:int;
		
		private var vMapEntities:Vector.<int>;;
		
		public function Room(point:FlxPoint, width:int, height:int, type:int) 
		{
			super(point.x, point.y, width, height);
			this.type = type;
			
			vMapEntities = new Vector.<int>();
		}
		
		public function release():void
		{
			vMapEntities = null;
		}
		
	}

}
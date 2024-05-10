package  
{
	import flash.display.Loader;
	/**
	 * ...
	 * @author Luiz F. A. de Prá
	 */
	public class Global
	{
		// XMLs
		public static var configXML:XML		= null;
		public static var mapXML:XML		= null;
		public static var playerXML:XML		= null;
		public static var monsterXML:XML	= null;
		
		public static function getRandom(min:int, max:int):int
		{
			var random:Number = Math.floor(Math.random() * (max - min + 1)) + min;
			return int(random);
		}	
	}

}
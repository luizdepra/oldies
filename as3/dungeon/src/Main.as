package  
{

	import flash.utils.ByteArray;
	import org.flixel.*;	
	import states.GenerationState;
	
	[SWF(width = "1024", height = "576", backgroundColor = "#000000")]
	//[Frame(factoryClass = "Preloader")]

	public class Main extends FlxGame
	{
		[Embed(source="data/xml/config.xml", mimeType="application/octet-stream")]	public static const cConfigXML:Class;
		[Embed(source="data/xml/map.xml", mimeType="application/octet-stream")]		public static const cMapXML:Class;
		[Embed(source="data/xml/player.xml", mimeType="application/octet-stream")]	public static const cPlayerXML:Class;
		[Embed(source="data/xml/monster.xml", mimeType="application/octet-stream")]	public static const cMonsterXML:Class;
		
		public function Main() 
		{
			var file:ByteArray = new cConfigXML;
			var str:String = file.readUTFBytes(file.length);
			Global.configXML = new XML(str);
			
			file = new cMapXML;
			str = file.readUTFBytes(file.length);
			Global.mapXML = new XML(str);
			
			file = new cPlayerXML;
			str = file.readUTFBytes(file.length);
			Global.playerXML = new XML(str);
			
			file = new cMonsterXML;
			str = file.readUTFBytes(file.length);
			Global.monsterXML = new XML(str);
			
			super(1024, 576, GenerationState, 1);
		}
		
	}

}
package states 
{
	import generator.DungeonGenerator;
	import map.Map;
	import org.flixel.*;
	
	/**
	 * ...
	 * @author Luiz F. A. de Prá
	 */
	public class GenerationState extends FlxState 
	{
		[Embed(source = "../data/img/screen/loading.png")] private var cLoadingImg:Class;
		
		// consts
		private const MIN_DUNGEON_LENGHT:int			= 50;
		private const MAX_DUNGEON_LENGHT:int			= 50;
		
		private const MIN_DUNGEON_ROOMS:int				= 10;
		private const MAX_DUNGEON_ROOMS:int				= 10;
		
		// Dungeon Generator Class
		private var cDunGen:DungeonGenerator;
		
		// Loading screen
		private var sprLoading:FlxSprite;
		
		private var count:int;
		
		public function GenerationState() 
		{
			cDunGen = new DungeonGenerator();
			
			sprLoading = new FlxSprite(800, 600, cLoadingImg);
			add(sprLoading);
			
			count = 0;
		}
		
		override public function create():void
		{
			// insert loading screen
		}
		
		override public function update():void
		{
			if (count == 0)
			{
				var width:int = Global.getRandom(MIN_DUNGEON_LENGHT, MAX_DUNGEON_LENGHT);
				var height:int = Global.getRandom(MIN_DUNGEON_LENGHT, MAX_DUNGEON_LENGHT);
				var rooms:int = Global.getRandom(MIN_DUNGEON_ROOMS, MAX_DUNGEON_ROOMS);
							
				var cMap:Map = cDunGen.generate(width, height, rooms);
				
				cMap.traceMap();
				
				//FlxG.state = new WorldState(map);
				count++;
			}
					
			
		}
		
	}

}
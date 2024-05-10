package generator 
{
	import map.Map;
	import map.Room;
	import map.Tile;
	import org.flixel.*;
	/**
	 * DungeonGenerator - Generate random dungeons
	 * @author Luiz F. A. de Prá
	 */
	public class DungeonGenerator
	{
		private var cMap:Map;
			
		private var iNumRooms:int;
		
		public function DungeonGenerator() 
		{
		}
		
		public function generate(width:int, height:int, nrooms:int):Map
		{
			cMap = new Map(width, height);
			iNumRooms = 0;
			
			// STEP 1: Fill the whole map with solid earth
			// not needed anymore
			
			// STEP 2: Dig out a single room in (the centre of?) the map
			var initPnt:FlxPoint = new FlxPoint(int(cMap.width / 2), int(cMap.height / 2));
			var room:Room = new Room(initPnt,
			                         Global.getRandom(int(Global.mapXML.generator.room.min_size), int(Global.mapXML.generator.room.max_size)),
									 Global.getRandom(int(Global.mapXML.generator.room.min_size), int(Global.mapXML.generator.room.max_size)),
									 Room.TYPE_SQUARE_ROOM);
			
			cMap.addRoom(room);
			
			iNumRooms++;
			
			// STEP 3: Pick a wall of any room
			var room:Room;
			var wallPoint:FlxPoint;
			var dir:int;
			while (iNumObjects < nobj)
			{
				for (var i:int = 0; i < int(Global.mapXML.generator.max_tentatives); i++ )
				{			
					room = cMap.getRandomRoom();
					
					// STEP 4: Decide upon a new feature to build
					// STEP 5: See if there is room to add the new feature through the chosen wall
					// STEP 6: If yes, continue. If no, go back to step 3
					// STEP 7: Add the feature through the chosen wall
					var nextFeature:int = Global.getRandom(0, 100);
					var ret:Boolean;
					var chance:int;
					if (vRooms[vRooms.length - 1].type == Room.TYPE_CORRIDOR)
						chance = ROOM_EXTRA_CHANCE;
					else
						chance = ROOM_CHANCE;
					if (nextFeature < chance)
						ret = makeRoom(wallPoint, MAX_ROOM_SIZE, MAX_ROOM_SIZE, dir);
					else
						ret = makeCorridor(wallPoint, MAX_ROOM_SIZE, dir);
					
					if (ret)
					{
						iNumObjects++;
						break;
					}
				} // (while) STEP 8: Go back to step 3, until the dungeon is complete
			}
			
			// STEP 9: Add the up and down staircases at random points in map
			//setPlayerStart();
			
			// STEP 10: Finally, sprinkle some monsters and items liberally over dungeon*/
			
			return cMap;
		}
	}
}
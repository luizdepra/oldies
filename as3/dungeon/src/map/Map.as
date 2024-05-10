package map 
{
	import flash.geom.Point;
	import org.flixel.*;
	/**
	 * ...
	 * @author Luiz F. A. de Prá (aka RawArkanis)
	 */
	public class Map
	{
		// vector of tiles
		private var vRooms:Vector.<Room>;
		
		// dimensions
		private var iWidth:int;
		private var iHeight:int;
		
		// player
		private var pPlayerStart:Point;
		
		public function Map(width:int, height:int) 
		{
			iWidth = width;
			iHeight = height;
			
			vRooms = new Vector.<Room>();			
		}
		
		public function get width():int
		{
			return iWidth;
		}
		
		public function get height():int
		{
			return iHeight;
		}
		
		public function addRoom(room:Room):Boolean
		{
			if (checkRoomCollision(room))
				return false;
			
			vRooms.push(room);
				
			return true;
		}
		
		public function toMatrix():Vector.<Vector.<int>>
		{
			var vTiles:Vector.<Vector.<int>> = new Vector.<Vector.<int>>();
			var i:int;
			var j:int;
			
			// fill with solid rock
			for (i = 0; i < iWidth; i++)
			{
				vTiles[i] = new Vector.<int>();
				
				for (j = 0; j < iHeight; j++)
				{
					vTiles[i][j] = Tile.TILETYPE_EMPTY;
				}
			}
			
			for (var room:int = 0; room < vRooms.length; room++)
			{
				for (i = vRooms[room].x; i < vRooms[room].x + vRooms[room].width; i++)
				{
					trace("TESTE 01");
					for (j = vRooms[room].y; j < vRooms[room].y + vRooms[room].height; j++)
					{
						trace("TESTE 02");
						vTiles[i][j] = Tile.TILETYPE_FLOOR;
					}
				}
			}
			
			return vTiles;
		}
		
		public function toCSV():String
		{
			var str:String = new String();
			var vTiles:Vector.<Vector.<int>> = toMatrix();
			
			for (var j:int = 0; j < iHeight; j++)
			{
				for (var i:int = 0; i < iWidth; i++)
				{
					str += vTiles[i][j] + ",";
				}
				
				str += "\n";
			}
			
			return str;
		}
		
		public function traceMap():void
		{
			var str:String;
			var vTiles:Vector.<Vector.<int>> = toMatrix();
			
			for (var j:int = 0; j < iHeight; j++)
			{
				str = new String();
				
				for (var i:int = 0; i < iWidth; i++)
				{
					str += vTiles[i][j] + " ";
				}
				
				trace(str);
			}
		}
		
		private function checkRoomCollision(newRoom:Room):Boolean
		{
			for each (var room:Room in vRooms)
			{
				if (newRoom.bottom < room.top)
					return true;
				if (newRoom.top > room.bottom)
					return true;
				if (newRoom.right < room.left)
					return true;
				if (newRoom.left > room.right)
					return true;
			}
			
			return false;
		}
	}

}
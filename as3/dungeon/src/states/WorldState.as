package states 
{
	import entities.Entity;
	import entities.Player;
	import flash.geom.Point;
	import map.Map;
	import map.MapManager;
	import map.Tile;
	import org.flixel.*;
	import org.flixel.data.FlxAnim;
	
	/**
	 * ...
	 * @author Luiz F. A. de Prá
	 */
	public class WorldState extends FlxState 
	{
		[Embed(source = "../data/img/tileset/tileset01.png")] private var cTilesetImg:Class;
		
		private var cMap:Map;
		private var cMapManager:MapManager;
		
		private var cPlayer:Player;
		
		private var bPressed:Boolean;
		private var pnt:Point;
		
		public function WorldState(map:Map) 
		{
			cMap = map;
			cMapManager = new MapManager(cMap, cTilesetImg);
			cPlayer = new Player();
			
			bPressed = false;
		}
		
		override public function create():void
		{
			add(cMapManager);
			cMapManager.attachPlayer(cPlayer);
		}
	
		private function doTurn():void
		{
			
		}
		
		override public function update():void
		{
			// TODO permitir facing quando não pode mover e não gastar turno
			
			if (FlxG.keys.justPressed("UP") && !bPressed && !cPlayer.isMoving())
			{
				pnt = cPlayer.getPosition();
				
				bPressed = true;
				cPlayer.setFacing(Entity.FACING_UP);
				
				if (cMap.getTile(pnt.x, pnt.y - 1).type != Tile.TILETYPE_WALL)
				{
					cPlayer.setMoving();
					doTurn();
				}
			}
			
			if (FlxG.keys.justPressed("DOWN") && !bPressed && !cPlayer.isMoving())
			{
				pnt = cPlayer.getPosition();
				
				bPressed = true;
				cPlayer.setFacing(Entity.FACING_DOWN);
				
				if (cMap.getTile(pnt.x, pnt.y + 1).type != Tile.TILETYPE_WALL)
				{
					cPlayer.setMoving();
					doTurn();
				}
			}
			
			if (FlxG.keys.justPressed("LEFT") && !bPressed && !cPlayer.isMoving())
			{
				pnt = cPlayer.getPosition();
				
				bPressed = true;
				cPlayer.setFacing(Entity.FACING_LEFT);
				
				if (cMap.getTile(pnt.x - 1, pnt.y).type != Tile.TILETYPE_WALL)
				{
					cPlayer.setMoving();
					doTurn();
				}
			}
			
			if (FlxG.keys.justPressed("RIGHT") && !bPressed && !cPlayer.isMoving())
			{
				pnt = cPlayer.getPosition();
				
				bPressed = true;
				cPlayer.setFacing(Entity.FACING_RIGHT);
				
				if (cMap.getTile(pnt.x + 1, pnt.y).type != Tile.TILETYPE_WALL)
				{
					cPlayer.setMoving();
					doTurn();
				}
			}
			
			if (FlxG.keys.justReleased("UP") || FlxG.keys.justReleased("DOWN") ||
			    FlxG.keys.justReleased("LEFT") || FlxG.keys.justReleased("RIGHT"))
			{
				bPressed = false;
			}
			
			cMapManager.update();
			cPlayer.update();
			
			FlxG.follow(cPlayer, 1);
			
			super.update();
		}
		
	}

}
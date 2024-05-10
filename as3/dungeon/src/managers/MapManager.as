package map
{
	import entities.Entity;
	import entities.Player;
	import flash.geom.Point;
	import org.flixel.*;
	
	/**
	 * ...
	 * @author Tiago Ling Alexandre / Luiz Francisco Artigas de Prá
	 */
	public class MapManager extends FlxGroup
	{	
		private var cTilesetImg:Class;
		
		private var cMap:Map;
		private var vMovableEntities:Vector.<Entity>;
		private var cPlayer:Player;
		
		private var cTileMap:FlxTilemap;
			
		public function MapManager(map:Map, tileset:Class):void
		{			
			cMap = map;
			cTilesetImg = tileset;
			
			cTileMap = new FlxTilemap();
			cTileMap.loadMap(cMap.toCSV(), cTilesetImg, 64, 64);
			
			vMovableEntities = new Vector.<Entity>();
			cPlayer = null;
			
			add(cTileMap);
		}
		
		override public function update():void
		{	
			super.update();
		}
		
		public function attachPlayer(player:Player):void
		{
			cPlayer = player;
			add(player);
			
			var pnt:Point = cMap.getPlayerStart();
			if (!pnt)
				trace("Erro: PlayerStart não foi definido!");
			
			cPlayer.setPosition(pnt.x,pnt.y);
		}
		
		public function attachMovableEntity(entity:Entity):void
		{
			vMovableEntities.push(entity);
			add(entity);
		}
		
		public function depthSort():void
		{
			//grpObjects.members.sort(heightSort);
		}
		
		private function heightSort(a_thing:FlxObject, b_thing:FlxObject):Number
		{
			var a_height:Number = a_thing.y * 500 + a_thing.x;
			var b_height:Number = b_thing.y * 500 + b_thing.x;
			
			if (a_height > b_height)
				return 1;
			else if (a_height < b_height)
				return -1;
			else
				return 0;
		}
	}

}
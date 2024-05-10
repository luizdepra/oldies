package entities 
{
	import org.flixel.*;
	
	/**
	 * ...
	 * @author Luiz F. A. de Prá
	 */
	public class Player extends Entity
	{
		[Embed(source = "../data/img/entities/player.png")] private var cPlayerImg:Class;
		
		private const PLAYER_WIDTH:int			= 64;
		private const PLAYER_HEIGHT:int			= 96;
		
		public function Player() 
		{
			super();
			loadGraphic(cPlayerImg, true, false, PLAYER_WIDTH, PLAYER_HEIGHT, true);
			
			setupAnimation();
		}
		
		override public function setPosition(x:int, y:int):void
		{
			super.setPosition(x, y);
			
			this.y -= Global.TILE_SIZE - 16;
		}
		
	}

}
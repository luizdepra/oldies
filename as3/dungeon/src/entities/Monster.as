package entities 
{
	/**
	 * ...
	 * @author ...
	 */
	public class Monster extends Entity 
	{
		[Embed(source = "../data/img/entities/troll.png")] private var cMonsterImg:Class;
		
		private const MONSTER_WIDTH:int			= 64;
		private const MONSTER_HEIGHT:int		= 96;
		
		public function Monster() 
		{
			super();
			loadGraphic(cMonsterImg, true, false, MONSTER_WIDTH, MONSTER_HEIGHT, true);
			
			setupAnimation();
		}
		
		override public function setPosition(x:int, y:int):void
		{
			super.setPosition(x, y);
			
			this.y -= Global.TILE_SIZE - 16;
		}
		
	}

}
package entities 
{
	import flash.geom.Point;
	import org.flixel.*;
	
	/**
	 * ...
	 * @author ...
	 */
	public class Entity extends FlxSprite 
	{
		protected const MOVING_DELAY:Number		= 0.01;
		
		public static const FACING_UP:String 			= "up";
		public static const FACING_DOWN:String 			= "down";
		public static const FACING_LEFT:String 			= "left";
		public static const FACING_RIGHT:String 		= "right";
		
		protected var iGridX:int;
		protected var iGridY:int;
		
		protected var cParent:FlxObject;
				
		protected var sFacing:String;
		protected var bChangedFacing:Boolean;
		protected var bMoving:Boolean;
		protected var nMovingTimer:Number;
		protected var iPixelsMoved:int;
		
		public function Entity() 
		{
			super(0, 0);
			
			iGridX = 0;
			iGridY = 0;
			
			cParent = null;
			
			bChangedFacing = false;
			bMoving = false;
			nMovingTimer = 0;
			iPixelsMoved = 0;
		}
		
		protected function setupAnimation():void
		{
			addAnimation("idle_up", [12], 0, false);
			addAnimation("idle_down", [0], 0, false);
			addAnimation("idle_left", [4], 0, false);
			addAnimation("idle_right", [8], 0, false);
			addAnimation("move_up", [12,13,14,15], 3.5, true);
			addAnimation("move_down", [0,1,2,3], 3.5, true);
			addAnimation("move_left", [4,5,6,7], 3.5, true);
			addAnimation("move_right", [8,9,10,11], 3.5, true);
			play("idle_down");
		}
		
		public function setParent(parent:FlxObject):void
		{
			if (!cParent)
				cParent = parent;
		}
		
		public function setPosition(x:int, y:int):void
		{
			iGridX = x;
			iGridY = y;
			
			this.x = iGridX * Global.TILE_SIZE;
			this.y = iGridY * Global.TILE_SIZE;
		}
		
		public function getPosition():Point
		{
			return (new Point(iGridX, iGridY));
		}
		
				// TODO Mover para o Entity, monstros vão precisar disso
		public function setFacing(str:String):void
		{
			sFacing = str;
			bChangedFacing = true;
		}
	
		public function setMoving():void
		{
			bMoving = true;
			iPixelsMoved = 0;
			nMovingTimer = 0;
			play("move_" + sFacing);
		}
		
		public function isMoving():Boolean
		{
			return bMoving;
		}
		
		override public function update():void
		{
			if (bChangedFacing && !bMoving) // TODO isso sai depois
			{
				play("idle_" + sFacing);
				bChangedFacing = false;
			}
			else if (bMoving)
			{
				if (iPixelsMoved < Global.TILE_SIZE)
				{
					nMovingTimer += FlxG.elapsed;
					if (nMovingTimer >= MOVING_DELAY)
					{
						switch(sFacing)
						{
							case "up":
								this.y -= 1;
								break;
							case "down":
								this.y += 1;
								break;
							case "left":
								this.x -= 1;
								break;
							case "right":
								this.x += 1;
								break;
						}
						
						iPixelsMoved++;
						nMovingTimer = 0;
					}
				}
				else
				{
					switch(sFacing)
					{
						case "up":
							setPosition(iGridX, iGridY - 1);
							break;
						case "down":
							setPosition(iGridX, iGridY + 1);
							break;
						case "left":
							setPosition(iGridX - 1, iGridY);
							break;
						case "right":
							setPosition(iGridX + 1, iGridY);
							break;
					}
					
					bMoving = false;
					iPixelsMoved = 0;
					nMovingTimer = 0;
				}
			}
			
			super.update();
		}
	}

}
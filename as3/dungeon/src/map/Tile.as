package map 
{
	import flash.geom.Point;
	import org.flixel.*;
	/**
	 * ...
	 * @author Luiz F. A. de Prá (aka RawArkanis)
	 */
	public class Tile
	{
		// Tile types
		public static const TILETYPE_EMPTY:int 					= 0;
		public static const TILETYPE_FLOOR:int 					= 1;
		public static const TILETYPE_WALL:int 					= 2;
		public static const TILETYPE_CONNECTION:int				= 3;
		
		public static const SPRITETYPE_EMPTY:int 				= 0;
		public static const SPRITETYPE_FLOOR:int 				= 3;
		public static const SPRITETYPE_WALL_UP:int 				= 4;
		public static const SPRITETYPE_WALL_DOWN:int 			= 5;
		public static const SPRITETYPE_WALL_LEFT:int 			= 6;
		public static const SPRITETYPE_WALL_RIGHT:int 			= 7;
		public static const SPRITETYPE_WALL_UP_LEFT:int			= 8;
		public static const SPRITETYPE_WALL_UP_RIGHT:int		= 9;
		public static const SPRITETYPE_WALL_DOWN_LEFT:int		= 10;
		public static const SPRITETYPE_WALL_DOWN_RIGHT:int		= 11;
		public static const SPRITETYPE_WALL_LEFT_UP:int			= 12;
		public static const SPRITETYPE_WALL_RIGHT_UP:int		= 13;
		public static const SPRITETYPE_WALL_LEFT_DOWN:int		= 14;
		public static const SPRITETYPE_WALL_RIGHT_DOWN:int		= 15;
		public static const SPRITETYPE_WALL_OTHER:int			= 16;
	}

}
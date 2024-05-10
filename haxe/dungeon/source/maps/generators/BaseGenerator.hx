package maps.generators;

import maps.generators.bsp.BSPNode;
import maps.generators.rooms.BaseRoom;
import maps.scheme.MapScheme;

/**
 * @author Luiz F. A. de Prá
 */

class BaseGenerator 
{
	public var mapScheme(default, null):MapScheme;
	public var root(default, null):BSPNode;
	public var rooms(default, null):Array<BaseRoom>;
	
	public function generate():MapScheme
	{
		return null;
	}
}
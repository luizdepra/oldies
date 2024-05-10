package states;

import flixel.FlxState;

import maps.generators.DungeonGenerator;
import maps.Map;

/**
 * A FlxState which can be used for the actual gameplay.
 */
class PlayState extends FlxState
{
	private var _map:Map;
	/**
	 * Function that is called up when to state is created to set it up.
	 */
	override public function create():Void
	{
		super.create();

		var generator = new DungeonGenerator();
		var mapData = generator.generate();

		_map = new Map();
		_map.loadMapData(mapData);
		add(_map);
	}

	/**
	 * Function that is called when this state is destroyed - you might want to
	 * consider setting all objects this state uses to null to help garbage collection.
	 */
	override public function destroy():Void
	{
		super.destroy();
	}

	/**
	 * Function that is called once every frame.
	 */
	override public function update():Void
	{
		super.update();
	}
}

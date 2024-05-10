package maps.scheme;

class LayerScheme
{
	public var parent(default, null):MapScheme;
	
	public var width(default, null):Int;
	public var height(default, null):Int;

	public var tiles(default, null):Array<TileScheme>;

	public var tileArray(get, null):Array<Int>;

	public function new(parent:MapScheme)
	{
		this.parent = parent;
		this.width = parent.width;
		this.height = parent.height;

		tiles = new Array<TileScheme>();

		for (i in 0...width * height)
		{
			var tile = new TileScheme();
			tiles.push(tile);
		}
	}

	private function get_tileArray():Array<Int>
	{
		if (tileArray == null)
		{
			tileArray = new Array<Int>();

			for (tile in tiles)
			{
				tileArray.push(tile.id);
			}
		}

		return tileArray;
	}
}

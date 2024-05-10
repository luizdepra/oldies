package managers 
{
	import flash.display.Bitmap;
	/**
	 * ...
	 * @author ...
	 */
	public class ResourceManager 
	{
		private var vBitmap:Vector.<Bitmap>;
		
		public function ResourceManager() 
		{
			vBitmap = new Vector.<Bitmap>();
		}
		
		public function getBitmap(index:String):Bitmap
		{
			return vBitmap[index];
		}
		
		public function addBitmap(index:String, item:Bitmap):Boolean
		{
			if (vBitmap[index])
				return false;
				
			vBitmap[index] = item;
			return true;
		}
		
		public function removeBitmap(index:String):Bitmap
		{
			var tmp:Bitmap;
			
			tmp = vBitmap[index];
			vBitmap[index] = null;
			
			return tmp;
		}
	}

}
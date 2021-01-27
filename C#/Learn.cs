using System;

namespace Learning
{
	class Learn
	{
		double length;
		double width; 
		
		public void initial()
		{
			length = 4.5;
			width = 4.5;
		}
		
		public double getArea()
		{
			return length*width;
		}
		
		public void display()
		{
			Console.WriteLine("Area: {0}", getArea());
		} 
	}
	
	class Execute
	{
		static void Main(string[] args)
		{
			Learn obj = new Learn();
			obj.initial();
			obj.display();
			Console.ReadLine();
		}
	}
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace Geometry.Core
{
    public class Intersect
    {
        Point circleCenter;
        int circleRadius;
        
        Point segmentA;
        Point segmentB;

        int fieldSize;

        Bitmap buffer;
        Graphics drawer; 

        public Intersect (int fieldSize)
        {
            this.fieldSize = fieldSize;

            Random rnd = new Random();

            circleCenter = createPoint(rnd);
            segmentA = createPoint(rnd);
            segmentB = createPoint(rnd);

            circleRadius = rnd.Next(fieldSize / 8, fieldSize / 4);

            buffer = new Bitmap(fieldSize, fieldSize);
            drawer = Graphics.FromImage(buffer);
            drawer.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.HighQuality;
        }

        public bool AreIntersecting ()
        {
            var x  = circleCenter.X;
            var y  = circleCenter.Y;
            var x1 = segmentA.X;
            var y1 = segmentA.Y;
            var x2 = segmentB.X;
            var y2 = segmentB.Y;

            var deltaX = x2 - x1;
            var deltaY = y2 - y1;

			double a = Math.Pow (deltaX, 2) + Math.Pow (deltaY, 2);
			double b = 2 * ((deltaX) * (x1 - x) + (deltaY) * (y1 - y));
			double c = x * x + y * y + x1 * x1 + y1 * y1 - 2 * (x * x1 + y * y1) - circleRadius * circleRadius;

			if ( - b < 0)
			{
				return (c < 0);
			}

			if ( - b < (2 * a))
			{
				return (4 * a * c - b * b < 0);
			}

			return (a + b + c < 0);
        }

        public Bitmap Draw ()
        {
            drawer.Clear(System.Drawing.SystemColors.Window);

            drawer.DrawEllipse(System.Drawing.Pens.Black, circleCenter.X - circleRadius, circleCenter.Y - circleRadius, circleRadius * 2, circleRadius * 2);
            drawer.DrawLine(System.Drawing.Pens.Black, segmentA, segmentB);

            return buffer;
        }

        private Point createPoint(Random rnd)
        {
            return new Point(rnd.Next(fieldSize), rnd.Next(fieldSize));
        }

    }
}

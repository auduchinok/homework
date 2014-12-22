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

            circleRadius = rnd.Next(fieldSize / 4);

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

            var a = Math.Pow(deltaX, 2) + Math.Pow(deltaY, 2);
            var b = 2 * (Math.Abs(x1 - x) * deltaX + Math.Abs(y1 - y) * deltaY);
            var c = Math.Pow(x1 - x, 2) + Math.Pow(y1 - y, 2) - Math.Pow(circleRadius, 2);
            var d = b * b - 4 * a * c;

            if (d < 0) {
                return false;
            }
            else {
                var res1 = (-b + Math.Sqrt(d)) / (2 * a);
                var res2 = (-b - Math.Sqrt(d)) / (2 * a);
                return (res1 >= 0 && res1 <= 1) || (res2 >= 0 && res2 <= 1);
            }

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

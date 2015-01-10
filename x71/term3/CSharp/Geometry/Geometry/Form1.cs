using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Geometry.Core;

namespace Geometry
{
    public partial class Form1 : Form
    {
        const int fieldSize = 400;

        public Form1()
        {
            InitializeComponent();
        }

        private void generateButton_Click(object sender, EventArgs e)
        {
            Intersect intersect = new Intersect (fieldSize);
            intersectPreview.Image = intersect.Draw();

            if (intersect.AreIntersecting())
            {
                intersectLabel.Text = "Figures are intersecting";
            }
            else
            {
                intersectLabel.Text = "Figures are not intersecting";
            }
        }
    }
}

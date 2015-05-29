using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LocalizationDemo
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            string defaultPrice = Properties.Settings.Default.Price.ToString("C2");
            priceLabel.Text = defaultPrice;
            cheeseburgersTotalLabel.Text = defaultPrice;

            switch (Properties.Settings.Default.Language)
            {
                case "en":
                    confirmLink.Note = "You will be proceeded to a payment page";
                    cancelLink.Note = "Canceled order cannot be restored";
                    break;
                case "ru-RU":
                    confirmLink.Note = "Переход к странице оплаты";
                    confirmLink.Note = "Востановление заказа невозможно";
                    break;
            }
            

            
        }

        private void cheeseburgersCountSpin_ValueChanged(object sender, EventArgs e)
        {
            string cheeseburgersTotal = (Properties.Settings.Default.Price * cheeseburgersCountSpin.Value).ToString("C2");


            cheeseburgersTotalLabel.Text = cheeseburgersTotal;
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void commandLink2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            Program.Context.MainForm = new LanguageSetupForm();
            this.Close();
            Program.Context.MainForm.Show();
        }

        private void confirmLink_Click(object sender, EventArgs e)
        {
            this.Close();
        }


    }
}

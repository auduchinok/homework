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
    public partial class LanguageSetupForm : Form
    {
        public LanguageSetupForm()
        {
            InitializeComponent();
        }

        private void LanguageSetupForm_Load(object sender, EventArgs e)
        {

        }

        private void russianLanguageButton_Click(object sender, EventArgs e)
        {
            Properties.Settings.Default.Language = System.Globalization.CultureInfo.GetCultureInfo("ru-RU").ToString();
            Properties.Settings.Default.Price = 37.9m;
            SaveSettingsAndChangeContext();
        }

        private void englishLanguageButton_Click(object sender, EventArgs e)
        {
            Properties.Settings.Default.Language = System.Globalization.CultureInfo.GetCultureInfo("en").ToString();
            Properties.Settings.Default.Price = 1.2m;
            SaveSettingsAndChangeContext();
        }

        private void SaveSettingsAndChangeContext()
        {
            Properties.Settings.Default.Save();

            System.Threading.Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.GetCultureInfo(Properties.Settings.Default.Language);
            System.Threading.Thread.CurrentThread.CurrentUICulture = System.Globalization.CultureInfo.GetCultureInfo(Properties.Settings.Default.Language);
            Program.Context.MainForm = new MainForm();

            this.Close();
            Program.Context.MainForm.Show();
        }

        private void cancelButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        
    }
}

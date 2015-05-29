namespace LocalizationDemo
{
    partial class LanguageSetupForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(LanguageSetupForm));
            this.russianLanguageButton = new MaxKnor.VistaUI.CommandLink();
            this.englishLanguageButton = new MaxKnor.VistaUI.CommandLink();
            this.cancelButton = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // russianLanguageButton
            // 
            resources.ApplyResources(this.russianLanguageButton, "russianLanguageButton");
            this.russianLanguageButton.Name = "russianLanguageButton";
            this.russianLanguageButton.Note = "Запомнить выбор";
            this.russianLanguageButton.UseVisualStyleBackColor = true;
            this.russianLanguageButton.Click += new System.EventHandler(this.russianLanguageButton_Click);
            // 
            // englishLanguageButton
            // 
            resources.ApplyResources(this.englishLanguageButton, "englishLanguageButton");
            this.englishLanguageButton.Name = "englishLanguageButton";
            this.englishLanguageButton.Note = "Remember the choice";
            this.englishLanguageButton.UseVisualStyleBackColor = true;
            this.englishLanguageButton.Click += new System.EventHandler(this.englishLanguageButton_Click);
            // 
            // cancelButton
            // 
            resources.ApplyResources(this.cancelButton, "cancelButton");
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // LanguageSetupForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.CancelButton = this.cancelButton;
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.englishLanguageButton);
            this.Controls.Add(this.russianLanguageButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "LanguageSetupForm";
            this.Load += new System.EventHandler(this.LanguageSetupForm_Load);
            this.ResumeLayout(false);

        }

        #endregion

        private MaxKnor.VistaUI.CommandLink russianLanguageButton;
        private MaxKnor.VistaUI.CommandLink englishLanguageButton;
        private System.Windows.Forms.Button cancelButton;

    }
}
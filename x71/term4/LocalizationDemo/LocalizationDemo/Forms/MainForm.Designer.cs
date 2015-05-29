namespace LocalizationDemo
{
    partial class MainForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.label2 = new System.Windows.Forms.Label();
            this.priceLabel = new System.Windows.Forms.Label();
            this.cheeseburgersTotalLabel = new System.Windows.Forms.Label();
            this.cheeseburgersCountSpin = new System.Windows.Forms.NumericUpDown();
            this.cancelButton = new System.Windows.Forms.Button();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.cancelLink = new MaxKnor.VistaUI.CommandLink();
            this.confirmLink = new MaxKnor.VistaUI.CommandLink();
            ((System.ComponentModel.ISupportInitialize)(this.cheeseburgersCountSpin)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // label2
            // 
            resources.ApplyResources(this.label2, "label2");
            this.label2.Name = "label2";
            // 
            // priceLabel
            // 
            resources.ApplyResources(this.priceLabel, "priceLabel");
            this.priceLabel.Name = "priceLabel";
            // 
            // cheeseburgersTotalLabel
            // 
            resources.ApplyResources(this.cheeseburgersTotalLabel, "cheeseburgersTotalLabel");
            this.cheeseburgersTotalLabel.Name = "cheeseburgersTotalLabel";
            // 
            // cheeseburgersCountSpin
            // 
            resources.ApplyResources(this.cheeseburgersCountSpin, "cheeseburgersCountSpin");
            this.cheeseburgersCountSpin.Maximum = new decimal(new int[] {
            20,
            0,
            0,
            0});
            this.cheeseburgersCountSpin.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.cheeseburgersCountSpin.Name = "cheeseburgersCountSpin";
            this.cheeseburgersCountSpin.Value = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.cheeseburgersCountSpin.ValueChanged += new System.EventHandler(this.cheeseburgersCountSpin_ValueChanged);
            // 
            // cancelButton
            // 
            resources.ApplyResources(this.cancelButton, "cancelButton");
            this.cancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
            this.cancelButton.Name = "cancelButton";
            this.cancelButton.UseVisualStyleBackColor = true;
            this.cancelButton.Click += new System.EventHandler(this.cancelButton_Click);
            // 
            // linkLabel1
            // 
            resources.ApplyResources(this.linkLabel1, "linkLabel1");
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.TabStop = true;
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // pictureBox1
            // 
            resources.ApplyResources(this.pictureBox1, "pictureBox1");
            this.pictureBox1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox1.Image = global::LocalizationDemo.Properties.Resources.mcdonalds_Cheeseburger;
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.TabStop = false;
            // 
            // cancelLink
            // 
            resources.ApplyResources(this.cancelLink, "cancelLink");
            this.cancelLink.Name = "cancelLink";
            this.cancelLink.Note = "Отменённый заказ нельзя восстановить";
            this.cancelLink.UseVisualStyleBackColor = true;
            this.cancelLink.Click += new System.EventHandler(this.commandLink2_Click);
            // 
            // confirmLink
            // 
            resources.ApplyResources(this.confirmLink, "confirmLink");
            this.confirmLink.Name = "confirmLink";
            this.confirmLink.Note = "You will be proceeded to a payment page";
            this.confirmLink.UseVisualStyleBackColor = true;
            this.confirmLink.Click += new System.EventHandler(this.confirmLink_Click);
            // 
            // MainForm
            // 
            resources.ApplyResources(this, "$this");
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.CancelButton = this.cancelButton;
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.cancelButton);
            this.Controls.Add(this.cheeseburgersCountSpin);
            this.Controls.Add(this.cheeseburgersTotalLabel);
            this.Controls.Add(this.cancelLink);
            this.Controls.Add(this.confirmLink);
            this.Controls.Add(this.priceLabel);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.pictureBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.Name = "MainForm";
            this.Load += new System.EventHandler(this.MainForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.cheeseburgersCountSpin)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label priceLabel;
        private MaxKnor.VistaUI.CommandLink confirmLink;
        private MaxKnor.VistaUI.CommandLink cancelLink;
        private System.Windows.Forms.Label cheeseburgersTotalLabel;
        private System.Windows.Forms.NumericUpDown cheeseburgersCountSpin;
        private System.Windows.Forms.Button cancelButton;
        private System.Windows.Forms.LinkLabel linkLabel1;
    }
}


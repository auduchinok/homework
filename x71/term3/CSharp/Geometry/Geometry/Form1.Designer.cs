namespace Geometry
{
    partial class Form1
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
            this.intersectPreview = new System.Windows.Forms.PictureBox();
            this.generateButton = new System.Windows.Forms.Button();
            this.intersectLabel = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.intersectPreview)).BeginInit();
            this.SuspendLayout();
            // 
            // intersectPreview
            // 
            this.intersectPreview.BackColor = System.Drawing.SystemColors.Window;
            this.intersectPreview.Location = new System.Drawing.Point(12, 42);
            this.intersectPreview.Name = "intersectPreview";
            this.intersectPreview.Size = new System.Drawing.Size(400, 400);
            this.intersectPreview.TabIndex = 1;
            this.intersectPreview.TabStop = false;
            // 
            // generateButton
            // 
            this.generateButton.Location = new System.Drawing.Point(13, 13);
            this.generateButton.Name = "generateButton";
            this.generateButton.Size = new System.Drawing.Size(75, 23);
            this.generateButton.TabIndex = 0;
            this.generateButton.Text = "Generate";
            this.generateButton.UseVisualStyleBackColor = true;
            this.generateButton.Click += new System.EventHandler(this.generateButton_Click);
            // 
            // intersectLabel
            // 
            this.intersectLabel.AutoSize = true;
            this.intersectLabel.Location = new System.Drawing.Point(278, 18);
            this.intersectLabel.Name = "intersectLabel";
            this.intersectLabel.Size = new System.Drawing.Size(0, 13);
            this.intersectLabel.TabIndex = 2;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(424, 461);
            this.Controls.Add(this.intersectLabel);
            this.Controls.Add(this.intersectPreview);
            this.Controls.Add(this.generateButton);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "Intersect";
            ((System.ComponentModel.ISupportInitialize)(this.intersectPreview)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox intersectPreview;
        private System.Windows.Forms.Button generateButton;
        private System.Windows.Forms.Label intersectLabel;
    }
}


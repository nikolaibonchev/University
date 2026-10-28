namespace WindowsFormsApp1_3_
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
            this.Lantern_Corps = new System.Windows.Forms.ListBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.count = new System.Windows.Forms.Label();
            this.check_count = new System.Windows.Forms.Button();
            this.sort = new System.Windows.Forms.Button();
            this.remove = new System.Windows.Forms.Button();
            this.clear = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // Lantern_Corps
            // 
            this.Lantern_Corps.FormattingEnabled = true;
            this.Lantern_Corps.ItemHeight = 16;
            this.Lantern_Corps.Items.AddRange(new object[] {
            "Will Power",
            "Hope",
            "Anger",
            "Fear",
            "Greed",
            "Compasion",
            "Star Sapphire"});
            this.Lantern_Corps.Location = new System.Drawing.Point(297, 109);
            this.Lantern_Corps.Name = "Lantern_Corps";
            this.Lantern_Corps.SelectionMode = System.Windows.Forms.SelectionMode.MultiExtended;
            this.Lantern_Corps.Size = new System.Drawing.Size(256, 228);
            this.Lantern_Corps.TabIndex = 0;
            this.Lantern_Corps.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(297, 344);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(243, 22);
            this.textBox1.TabIndex = 1;
            this.textBox1.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(555, 344);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 22);
            this.button1.TabIndex = 2;
            this.button1.Text = "Add";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // count
            // 
            this.count.AutoSize = true;
            this.count.Location = new System.Drawing.Point(483, 375);
            this.count.Name = "count";
            this.count.Size = new System.Drawing.Size(39, 16);
            this.count.TabIndex = 3;
            this.count.Text = "count";
            // 
            // check_count
            // 
            this.check_count.Location = new System.Drawing.Point(555, 372);
            this.check_count.Name = "check_count";
            this.check_count.Size = new System.Drawing.Size(75, 23);
            this.check_count.TabIndex = 4;
            this.check_count.Text = "Check";
            this.check_count.UseVisualStyleBackColor = true;
            this.check_count.Click += new System.EventHandler(this.check_count_Click);
            // 
            // sort
            // 
            this.sort.Location = new System.Drawing.Point(559, 167);
            this.sort.Name = "sort";
            this.sort.Size = new System.Drawing.Size(75, 23);
            this.sort.TabIndex = 5;
            this.sort.Text = "Sort";
            this.sort.UseVisualStyleBackColor = true;
            this.sort.Click += new System.EventHandler(this.sort_Click);
            // 
            // remove
            // 
            this.remove.Location = new System.Drawing.Point(559, 138);
            this.remove.Name = "remove";
            this.remove.Size = new System.Drawing.Size(75, 23);
            this.remove.TabIndex = 6;
            this.remove.Text = "Remove";
            this.remove.UseVisualStyleBackColor = true;
            this.remove.Click += new System.EventHandler(this.remove_Click);
            // 
            // clear
            // 
            this.clear.Location = new System.Drawing.Point(559, 109);
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(75, 23);
            this.clear.TabIndex = 7;
            this.clear.Text = "Clear";
            this.clear.UseVisualStyleBackColor = true;
            this.clear.Click += new System.EventHandler(this.clear_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1360, 623);
            this.Controls.Add(this.clear);
            this.Controls.Add(this.remove);
            this.Controls.Add(this.sort);
            this.Controls.Add(this.check_count);
            this.Controls.Add(this.count);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.Lantern_Corps);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ListBox Lantern_Corps;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label count;
        private System.Windows.Forms.Button check_count;
        private System.Windows.Forms.Button sort;
        private System.Windows.Forms.Button remove;
        private System.Windows.Forms.Button clear;
    }
}


namespace WindowsFormsApp2_3._2_
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
            this.comboBox1 = new System.Windows.Forms.ComboBox();
            this.modelBox = new System.Windows.Forms.ComboBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.fromPicker = new System.Windows.Forms.DateTimePicker();
            this.untilPicker = new System.Windows.Forms.DateTimePicker();
            this.manufacturer = new System.Windows.Forms.Label();
            this.model = new System.Windows.Forms.Label();
            this.from = new System.Windows.Forms.Label();
            this.until = new System.Windows.Forms.Label();
            this.richTextBox1 = new System.Windows.Forms.RichTextBox();
            this.searchBtn = new System.Windows.Forms.Button();
            this.yearsList = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // comboBox1
            // 
            this.comboBox1.FormattingEnabled = true;
            this.comboBox1.Items.AddRange(new object[] {
            "BMW",
            "Mercedes",
            "Audi",
            "Lambourghini",
            "Ferrari",
            "Tesla",
            "Ford",
            "Mitsubishi",
            "Subaru",
            "Volkswaggen"});
            this.comboBox1.Location = new System.Drawing.Point(423, 127);
            this.comboBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.comboBox1.Name = "comboBox1";
            this.comboBox1.Size = new System.Drawing.Size(92, 21);
            this.comboBox1.TabIndex = 0;
            this.comboBox1.SelectedIndexChanged += new System.EventHandler(this.comboBox1_SelectedIndexChanged);
            // 
            // modelBox
            // 
            this.modelBox.FormattingEnabled = true;
            this.modelBox.Location = new System.Drawing.Point(519, 127);
            this.modelBox.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.modelBox.Name = "modelBox";
            this.modelBox.Size = new System.Drawing.Size(92, 21);
            this.modelBox.TabIndex = 1;
            this.modelBox.SelectedIndexChanged += new System.EventHandler(this.modelBox_SelectedIndexChanged);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(157, 127);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(261, 232);
            this.pictureBox1.TabIndex = 2;
            this.pictureBox1.TabStop = false;
            // 
            // fromPicker
            // 
            this.fromPicker.CustomFormat = "yyyy";
            this.fromPicker.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.fromPicker.Location = new System.Drawing.Point(617, 127);
            this.fromPicker.Name = "fromPicker";
            this.fromPicker.Size = new System.Drawing.Size(53, 20);
            this.fromPicker.TabIndex = 3;
            this.fromPicker.ValueChanged += new System.EventHandler(this.fromPicker_ValueChanged);
            // 
            // untilPicker
            // 
            this.untilPicker.CustomFormat = "yyyy";
            this.untilPicker.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.untilPicker.Location = new System.Drawing.Point(676, 128);
            this.untilPicker.Name = "untilPicker";
            this.untilPicker.Size = new System.Drawing.Size(56, 20);
            this.untilPicker.TabIndex = 4;
            // 
            // manufacturer
            // 
            this.manufacturer.AutoEllipsis = true;
            this.manufacturer.AutoSize = true;
            this.manufacturer.Location = new System.Drawing.Point(423, 109);
            this.manufacturer.Name = "manufacturer";
            this.manufacturer.Size = new System.Drawing.Size(70, 13);
            this.manufacturer.TabIndex = 5;
            this.manufacturer.Text = "Manufacturer";
            // 
            // model
            // 
            this.model.AutoSize = true;
            this.model.Location = new System.Drawing.Point(519, 109);
            this.model.Name = "model";
            this.model.Size = new System.Drawing.Size(36, 13);
            this.model.TabIndex = 6;
            this.model.Text = "Model";
            // 
            // from
            // 
            this.from.AutoSize = true;
            this.from.Location = new System.Drawing.Point(617, 109);
            this.from.Name = "from";
            this.from.Size = new System.Drawing.Size(30, 13);
            this.from.TabIndex = 7;
            this.from.Text = "From";
            this.from.Click += new System.EventHandler(this.label3_Click);
            // 
            // until
            // 
            this.until.AutoSize = true;
            this.until.Location = new System.Drawing.Point(676, 110);
            this.until.Name = "until";
            this.until.Size = new System.Drawing.Size(28, 13);
            this.until.TabIndex = 8;
            this.until.Text = "Until";
            // 
            // richTextBox1
            // 
            this.richTextBox1.Location = new System.Drawing.Point(424, 154);
            this.richTextBox1.Name = "richTextBox1";
            this.richTextBox1.Size = new System.Drawing.Size(308, 205);
            this.richTextBox1.TabIndex = 9;
            this.richTextBox1.Text = "";
            // 
            // searchBtn
            // 
            this.searchBtn.Location = new System.Drawing.Point(739, 124);
            this.searchBtn.Name = "searchBtn";
            this.searchBtn.Size = new System.Drawing.Size(75, 23);
            this.searchBtn.TabIndex = 10;
            this.searchBtn.Text = "search";
            this.searchBtn.UseVisualStyleBackColor = true;
            this.searchBtn.Click += new System.EventHandler(this.searchBtn_Click);
            // 
            // yearsList
            // 
            this.yearsList.FormattingEnabled = true;
            this.yearsList.Location = new System.Drawing.Point(739, 154);
            this.yearsList.Name = "yearsList";
            this.yearsList.Size = new System.Drawing.Size(75, 69);
            this.yearsList.TabIndex = 11;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(927, 556);
            this.Controls.Add(this.yearsList);
            this.Controls.Add(this.searchBtn);
            this.Controls.Add(this.richTextBox1);
            this.Controls.Add(this.until);
            this.Controls.Add(this.from);
            this.Controls.Add(this.model);
            this.Controls.Add(this.manufacturer);
            this.Controls.Add(this.untilPicker);
            this.Controls.Add(this.fromPicker);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.modelBox);
            this.Controls.Add(this.comboBox1);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboBox1;
        private System.Windows.Forms.ComboBox modelBox;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.DateTimePicker fromPicker;
        private System.Windows.Forms.DateTimePicker untilPicker;
        private System.Windows.Forms.Label manufacturer;
        private System.Windows.Forms.Label model;
        private System.Windows.Forms.Label from;
        private System.Windows.Forms.Label until;
        private System.Windows.Forms.RichTextBox richTextBox1;
        private System.Windows.Forms.Button searchBtn;
        private System.Windows.Forms.ListBox yearsList;
    }
}


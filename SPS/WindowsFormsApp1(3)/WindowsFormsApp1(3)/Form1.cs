using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1_3_
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Lantern_Corps.Items.Add(textBox1.Text);
            textBox1.Text = "";
            textBox1.Focus();
        }

        private void check_count_Click(object sender, EventArgs e)
        {
            count.Text = "count: " + Lantern_Corps.Items.Count;
        }

        private void sort_Click(object sender, EventArgs e)
        {
            Lantern_Corps.Sorted = true;
        }

        private void remove_Click(object sender, EventArgs e)
        {
            if (Lantern_Corps.SelectedItem != null) { 
                Lantern_Corps.Items.Remove(Lantern_Corps.SelectedItem);
            }
        }

        private void clear_Click(object sender, EventArgs e)
        {
            Lantern_Corps.Items.Clear();
        }
    }
}

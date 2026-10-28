using System;
using System.Windows.Forms;

namespace PersonBehaviourMarkovModel
{
    public partial class Form1 : Form
    {
        double grow_grow, grow_same, grow_falls;
        double same_grow, same_same, same_falls;
        double falls_grow, falls_same, falls_falls;

        public Form1()
        {
            InitializeComponent();
        }

        private void btnShowData_Click(object sender, EventArgs e)
        {
            grow_grow = 0.4; grow_same = 0.6; grow_falls = 0.0;
            same_grow = 0.03; same_same = 0.9; same_falls = 0.07;
            falls_grow = 0.2; falls_same = 0.4; falls_falls = 0.4;

            lblData1.Text = Convert.ToString(grow_grow) + ", " +
                            Convert.ToString(grow_same) + ", " +
                            Convert.ToString(grow_falls);

            lblData2.Text = Convert.ToString(same_grow) + ", " +
                            Convert.ToString(same_same) + ", " +
                            Convert.ToString(same_falls);

            lblData3.Text = Convert.ToString(falls_grow) + ", " +
                            Convert.ToString(falls_same) + ", " +
                            Convert.ToString(falls_falls);
        }
        private void btnCalculateProbability_Click(object sender, EventArgs e)
        {
            if (rbDay1Grow.Checked == true &&
                rbDay2Grow.Checked == true &&
                rbDay3Same.Checked == true)
            {
                lblProbabilityShow.Text = Convert.ToString(grow_grow * grow_same);
            }
            else if (rbDay1Falls.Checked == true &&
                     rbDay3Same.Checked == true)
            {
                double probability = (falls_falls * falls_same) +
                                     (falls_same * same_same) +
                                     (falls_grow * grow_same);

                lblProbabilityShow.Text = Convert.ToString(probability);
            }
            else
            {
                lblProbabilityShow.Text = "There is no calculated data.";
            }
        }
    }
}
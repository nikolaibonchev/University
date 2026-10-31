using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Collections.Generic;

namespace WindowsFormsApp2_3._2_
{
    public partial class Form1 : Form
    {
        string carDesc = " Комфорт: Климатроник, Кожен салон, Ел.стъкла, Ел.огледала, Ел.седалки, Подгряване на седалки, Шибедах, Стерео уредба, Алуминиеви джанти, DVD/TV, Мултифункционален волан\r\nСигурност: ABS, ESP, Airbag, Халогенни фарове, ASR/Тракшън контрол, Парктроник, Центр. заключване, Старт-Стоп система, Безключово палене\r\nДруго: Типтроник/Мултитроник, Автопилот, Серво управление, Бордови компютър, Сервизна книжка, Навигационна система, Панорамен покрив ";
        public Form1()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        Dictionary<string, string[]> carArr = new Dictionary<string, string[]>
{
    { "BMW", new[] { "7 series", "XM", "M5" } },
    { "Mercedes", new[] { "A-Class", "C-Class", "GLC" } },
    { "Audi", new[] { "A3", "A4", "Q7" } },
    { "Volvo", new[] { "V40", "XC60", "S40" } },
    { "Honda", new[] { "Civic", "Accord", "CR-V" } },
    { "Tesla", new[] { "Model Y", "Model 3", "Model X" } },
    { "Ford", new[] { "Courier", "Focus", "Fiesta" } },
    { "Mitsubishi", new[] { "Lancer", "Outlander", "Sigma" } },
    { "Subaru", new[] { "WRX", "Impreza", "XV" } },
    { "Volkswaggen", new[] { "Golf", "Tiguan", "Passat" } }
};
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string car = comboBox1.SelectedItem.ToString();
            richTextBox1.Text = carDesc;

            if (comboBox1.SelectedItem != null)
            {
                string[] models = carArr[car];
                modelBox.Items.Clear();
                
                foreach (string model in models) {
                    modelBox.Items.Add(model);
                } 
            }
        }

        private void fromPicker_ValueChanged(object sender, EventArgs e)
        {
            untilPicker.Value = fromPicker.Value;
        }

        private void searchBtn_Click(object sender, EventArgs e)
        {
            if (comboBox1.SelectedItem != null && modelBox.SelectedItem != null)
            {
                string brand = comboBox1.SelectedItem.ToString();
                string model = modelBox.SelectedItem.ToString();

                string startYear = fromPicker.Value.Year.ToString();

                string imagePath = System.IO.Path.Combine(Application.StartupPath, "..", "..", "images", brand, model, startYear + ".jpg");

                if (System.IO.File.Exists(imagePath))
                {
                    pictureBox1.Image = Image.FromFile(imagePath);
                    pictureBox1.SizeMode = PictureBoxSizeMode.Zoom;
                }
                else
                {
                    pictureBox1.Image = null;
                    MessageBox.Show($"Няма намерена снимка за генерация, започваща през {startYear} г.");
                }
            }
        }

        private void modelBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(modelBox.SelectedItem != null)
            {
                string brand = comboBox1.SelectedItem.ToString();
                string model = modelBox.SelectedItem.ToString();

                yearsList.Items.Clear();

                string folderPath = System.IO.Path.Combine(Application.StartupPath, "..", "..", "images", brand, model);

                if (System.IO.Directory.Exists(folderPath))
                {
                    string[] files = System.IO.Directory.GetFiles(folderPath, "*.jpg"); // Търсим само .jpg

                    foreach (string file in files)
                    {
                        string year = System.IO.Path.GetFileNameWithoutExtension(file);

                        yearsList.Items.Add(year);
                    }
                }
                else
                {
                    yearsList.Items.Add("Няма данни");
                }
            }
        }
    }
}

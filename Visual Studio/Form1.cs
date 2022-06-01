using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ODEV5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)//Fakülte Ekle button
        {
            Form6 form6 = new Form6();
            form6.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)//Bölüm Ekle button
        {
            Form4 form4 = new Form4();
            form4.ShowDialog();
        }

        private void button3_Click(object sender, EventArgs e)//Öğrenci Ekle button
        {
            Form2 form2 = new Form2();
            form2.ShowDialog();
        }

        private void button4_Click(object sender, EventArgs e)//Öğrenci-Ders Sorgula button
        {
            Form7 form7 = new Form7();
            form7.ShowDialog();
        }

        private void button5_Click(object sender, EventArgs e)//Ders Ekle button
        {
            Form3 form3 = new Form3();
            form3.ShowDialog();
        }
    }
}

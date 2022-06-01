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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            Model1 veriTabanı = new Model1();

            dataGridView1.DataSource = veriTabanı.tBolums.ToList();

            comboBox1.DataSource = veriTabanı.tFakultes.ToList();
            comboBox1.DisplayMember = "FakulteAd";
            comboBox1.ValueMember = "FakulteID";
        }

        private void textBox1_TextChanged(object sender, EventArgs e) //Bolum ID textbox
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)//Bolum Adı textbox
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)//Fakülte ID combobox
        {

        }

        private void button1_Click(object sender, EventArgs e)//Ekle button
        {
            Model1 veriTabanı = new Model1();
            tBolum BolumFormu = new tBolum();
            BolumFormu.bolumID = Int16.Parse(textBox1.Text);
            BolumFormu.bolumAd = textBox2.Text;
            BolumFormu.fakulteID = (int)comboBox1.SelectedValue;
            veriTabanı.tBolums.Add(BolumFormu);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tBolums.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void button2_Click(object sender, EventArgs e)//Güncelle button
        {
            Model1 veriTabanı = new Model1();
            int guncel_id = Int16.Parse(textBox1.Text);
            tBolum guncel_bolum = veriTabanı.tBolums.SingleOrDefault(bolum => bolum.bolumID == guncel_id);
            guncel_bolum.bolumID = Int16.Parse(textBox1.Text);
            guncel_bolum.bolumAd = textBox2.Text;
            guncel_bolum.fakulteID = (int)comboBox1.SelectedValue;
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tBolums.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void button3_Click(object sender, EventArgs e)//Sil button
        {
            Model1 veriTabanı = new Model1();
            int sil_id = Int16.Parse(textBox1.Text);
            tBolum sil_bolum = veriTabanı.tBolums.SingleOrDefault(bolum => bolum.bolumID == sil_id);
            veriTabanı.tBolums.Remove(sil_bolum);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tBolums.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)//Verileri listeleyen datagridview
        {
            DataGridViewRow satir = dataGridView1.CurrentRow;
            textBox1.Text = satir.Cells["Bolum ID"].Value.ToString();
            textBox2.Text = satir.Cells["Bolum Adı"].Value.ToString();
            comboBox1.SelectedValue = satir.Cells["Fakulte ID"].Value;

        }

        private void button4_Click(object sender, EventArgs e)//Temizle button
        {
            textBox1.Clear();
            textBox2.Clear();
        }
    }
}

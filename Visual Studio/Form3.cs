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
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
        {
            Model1 veriTabanı = new Model1();

            dataGridView1.DataSource = veriTabanı.tDers.ToList();

            comboBox1.DataSource = veriTabanı.tBolums.ToList();
            comboBox1.DisplayMember = "bolumAd";
            comboBox1.ValueMember = "bolumID";

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e) //verileri listeleyen datagridview
        {
            DataGridViewRow satir = dataGridView1.CurrentRow;
            textBox1.Text = satir.Cells["Ders ID"].Value.ToString();
            textBox2.Text = satir.Cells["Ders Ad"].Value.ToString();
            comboBox1.SelectedValue = satir.Cells["Bolum ID"].Value;

        }

        private void textBox1_TextChanged(object sender, EventArgs e) //Ders ID textbox
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e) //Ders Adı textbox
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e) // Bölüm ID combobox
        {

        }

        private void button1_Click(object sender, EventArgs e) //Ekle button
        {
            Model1 veriTabanı = new Model1();
            tDer dersFormu = new tDer();
            dersFormu.dersID = Int16.Parse(textBox1.Text);
            dersFormu.dersAD = textBox2.Text;
            dersFormu.bolumID = (int)comboBox1.SelectedValue;
            veriTabanı.tDers.Add(dersFormu);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tDers.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void button2_Click(object sender, EventArgs e) //Güncelle button
        {
            Model1 veriTabanı = new Model1();
            int guncel_id = Int16.Parse(textBox1.Text);
            tDer guncel_ders = veriTabanı.tDers.SingleOrDefault(ders => ders.dersID == guncel_id);
            guncel_ders.dersID = Int16.Parse(textBox1.Text);
            guncel_ders.dersAD = textBox2.Text;
            guncel_ders.bolumID = (int)comboBox1.SelectedValue;
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tDers.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void button3_Click(object sender, EventArgs e) //Sil button
        {

            Model1 veriTabanı = new Model1();
            int sil_id = Int16.Parse(textBox1.Text);
            tDer sil_ders = veriTabanı.tDers.SingleOrDefault(ogrenci => ogrenci.dersID == sil_id);
            veriTabanı.tDers.Remove(sil_ders);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tDers.ToList();

            textBox1.Clear();
            textBox2.Clear();
        }

        private void button4_Click(object sender, EventArgs e)//Temizle button
        {
            textBox1.Clear();
            textBox2.Clear();

        }
    }
}

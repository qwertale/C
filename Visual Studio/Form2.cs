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
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void label2_Click(object sender, EventArgs e) // Öğrenci ID labeli
        {

        }

        //private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        //{

        //}

        private void textBox2_TextChanged(object sender, EventArgs e)  // Öğrenci ID textbox
        {

        }

        private void label3_Click(object sender, EventArgs e) // Öğrenci Ad labeli
        {

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            Model1 veriTabanı = new Model1();

            dataGridView1.DataSource = veriTabanı.tOgrencis.ToList();

            comboBox1.DataSource = veriTabanı.tBolums.ToList();
            comboBox1.DisplayMember = "bolumAd";
            comboBox1.ValueMember = "bolumID";

        }

        private void dataGridView1_CellContentClick_1(object sender, DataGridViewCellEventArgs e) //verileri listeleyen datagridview
        {
            DataGridViewRow satir = dataGridView1.CurrentRow;
            textBox2.Text = satir.Cells["Ogrenci ID"].Value.ToString();
            textBox3.Text = satir.Cells["Ogrenci Ad"].Value.ToString();
            textBox1.Text = satir.Cells["Ogrenci Soyad"].Value.ToString();
            comboBox1.SelectedValue = satir.Cells["Bolum ID"].Value;

        }

        private void textBox3_TextChanged(object sender, EventArgs e) // Öğrenci Ad textbox
        {

        }

        private void SOYAD_Click(object sender, EventArgs e) // bölüm Adı label
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e) // bölüm ID combobox
        {

        }

        private void label1_Click(object sender, EventArgs e) // öğrenci Soyad label
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e) // öğrenci soyadı textbox
        {

        }

        private void button1_Click(object sender, EventArgs e) // ekle button
        {
            Model1 veriTabanı = new Model1(); 
            tOgrenci ogrenciFormu = new tOgrenci();
            ogrenciFormu.ogrenciID = Int16.Parse(textBox2.Text);
            ogrenciFormu.ogrenciAd = textBox3.Text;
            ogrenciFormu.ogrenciSoyad = textBox1.Text;
            ogrenciFormu.bolumID = (int)comboBox1.SelectedValue;
            veriTabanı.tOgrencis.Add(ogrenciFormu); 
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tOgrencis.ToList();

            textBox3.Clear();
            textBox2.Clear();
            textBox1.Clear();

        }

        private void button2_Click(object sender, EventArgs e) // güncelle button
        {
            Model1 veriTabanı = new Model1();
            int guncel_id = Int16.Parse(textBox2.Text);
            tOgrenci guncel_ogrenci = veriTabanı.tOgrencis.SingleOrDefault(ogrenci => ogrenci.ogrenciID == guncel_id);
            guncel_ogrenci.ogrenciID = Int16.Parse(textBox2.Text);
            guncel_ogrenci.ogrenciAd = textBox3.Text;
            guncel_ogrenci.ogrenciSoyad = textBox1.Text;
            guncel_ogrenci.bolumID = (int)comboBox1.SelectedValue;

            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tOgrencis.ToList();

            textBox3.Clear();
            textBox2.Clear();
            textBox1.Clear();

        }

        private void button3_Click(object sender, EventArgs e) // sil button
        {
            Model1 veriTabanı = new Model1();
            int sil_id = Int16.Parse(textBox2.Text);
            tOgrenci sil_ogrenci = veriTabanı.tOgrencis.SingleOrDefault(ogrenci => ogrenci.ogrenciID == sil_id);
            veriTabanı.tOgrencis.Remove(sil_ogrenci);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tOgrencis.ToList();

            textBox3.Clear();
            textBox2.Clear();
            textBox1.Clear();

        }
        
        private void button4_Click(object sender, EventArgs e)//temizle button
        {
            textBox3.Clear();
            textBox2.Clear();
            textBox1.Clear();
        }
        
    }
}

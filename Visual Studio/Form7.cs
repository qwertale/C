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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void Form7_Load(object sender, EventArgs e)
        {
            Model1 veriTabanı = new Model1();

            dataGridView1.DataSource = veriTabanı.tOgrenciDers.ToList();

            comboBox1.DataSource = veriTabanı.tDers.ToList();
            comboBox1.DisplayMember = "dersAD";
            comboBox1.ValueMember = "dersID";
        }

        private void textBox1_TextChanged(object sender, EventArgs e)//Öğrenci-Ders ID textbox
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)//Öğrenci ID textbox
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)//Ders ID combobox
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)//Yıl textbox
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)//Yarıyıl textbox
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)//Vize textbox
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)//Final textbox
        {

        }

        private void button1_Click(object sender, EventArgs e)//Ekle button
        {
            Model1 veriTabanı = new Model1();
            tOgrenciDer ogrenciDersFormu = new tOgrenciDer();
            ogrenciDersFormu.ogrenciID = Int16.Parse(textBox2.Text);
            ogrenciDersFormu.ogrenciDersID = Int16.Parse(textBox1.Text);
            ogrenciDersFormu.yil = textBox3.Text;
            ogrenciDersFormu.yariyil = textBox5.Text;
            ogrenciDersFormu.vize = Int16.Parse(textBox4.Text);
            ogrenciDersFormu.final = Int16.Parse(textBox6.Text);
            ogrenciDersFormu.dersID = (int)comboBox1.SelectedValue;
            veriTabanı.tOgrenciDers.Add(ogrenciDersFormu);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tOgrenciDers.ToList();

            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox4.Clear();
            textBox5.Clear();
            textBox6.Clear();

        }

        private void button2_Click(object sender, EventArgs e)//Güncelle button
        {
            Model1 veriTabanı = new Model1();
            int guncel_id = Int16.Parse(textBox2.Text);
            tOgrenciDer guncel_ogrenciDers = veriTabanı.tOgrenciDers.SingleOrDefault(ogrenciDers => ogrenciDers.ogrenciDersID == guncel_id);
            guncel_ogrenciDers.ogrenciID = Int16.Parse(textBox2.Text);
            guncel_ogrenciDers.ogrenciDersID = Int16.Parse(textBox1.Text);
            guncel_ogrenciDers.yil = textBox3.Text;
            guncel_ogrenciDers.yariyil = textBox5.Text;
            guncel_ogrenciDers.vize = Int16.Parse(textBox4.Text);
            guncel_ogrenciDers.final = Int16.Parse(textBox6.Text);
            guncel_ogrenciDers.dersID = (int)comboBox1.SelectedValue;
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tOgrenciDers.ToList();

            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox4.Clear();
            textBox5.Clear();
            textBox6.Clear();

        }

        private void button4_Click(object sender, EventArgs e)//Sil button
        {
            Model1 veriTabanı = new Model1();
            int sil_id = Int16.Parse(textBox1.Text);
            tOgrenciDer sil_ogrenciDers = veriTabanı.tOgrenciDers.SingleOrDefault(ogrenciDers => ogrenciDers.ogrenciDersID == sil_id);
            veriTabanı.tOgrenciDers.Remove(sil_ogrenciDers);
            veriTabanı.SaveChanges();

        }

        private void button3_Click(object sender, EventArgs e)//temizle button
        {
            textBox1.Clear();
            textBox2.Clear();
            textBox3.Clear();
            textBox4.Clear();
            textBox5.Clear();
            textBox6.Clear();

        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)//verileri listeleyen gridview
        {
            DataGridViewRow satir = dataGridView1.CurrentRow;
            textBox1.Text = satir.Cells["Ogrenci-Ders ID"].Value.ToString();
            textBox2.Text = satir.Cells["Ogrenci ID"].Value.ToString();
            textBox3.Text = satir.Cells["Yıl"].Value.ToString();
            textBox4.Text = satir.Cells["Vize"].Value.ToString();
            textBox5.Text = satir.Cells["Yarıyıl"].Value.ToString();
            textBox6.Text = satir.Cells["Final"].Value.ToString();
            comboBox1.SelectedValue = satir.Cells["Ders ID"].Value;

        }

        private void textBox8_TextChanged(object sender, EventArgs e)//Öğrenci Filtreleme textbox
        {
            Model1 veriTabanı = new Model1();
            dataGridView1.DataSource = veriTabanı.tOgrenciDers.Where(ders => ders.dersID.Equals(textBox8.Text));

        }

        private void textBox7_TextChanged(object sender, EventArgs e)//Ders Fitreleme textbox
        {
            Model1 veriTabanı = new Model1();
            dataGridView1.DataSource = veriTabanı.tOgrenciDers.Where(ogrenci => ogrenci.ogrenciID.Equals(textBox7.Text));
            //equels dedik ama hayırlısı
        }
    }
}

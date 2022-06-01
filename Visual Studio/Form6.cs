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
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)//Verileri listeleyen datagridview
        {
            DataGridViewRow satir = dataGridView1.CurrentRow;
            textBox1.Text = satir.Cells["FakulteAd"].Value.ToString();
            textBox2.Text = satir.Cells["FakulteID"].Value.ToString();

        }

        private void textBox1_TextChanged(object sender, EventArgs e)//fakülte adı textbox
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)//fakülte ID textbox
        {

        }

        private void button1_Click(object sender, EventArgs e)//Ekle button
        {
            Model1 veriTabanı = new Model1();
            tFakulte fakulteFormu = new tFakulte();
            fakulteFormu.fakulteID = Int16.Parse(textBox2.Text);
            fakulteFormu.fakulteAd = textBox1.Text;
            veriTabanı.tFakultes.Add(fakulteFormu);
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tFakultes.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void button2_Click(object sender, EventArgs e)//Güncelle button
        {
            Model1 veriTabanı = new Model1();
            int guncel_id = Int16.Parse(textBox2.Text);
            tFakulte guncel_fakulte = veriTabanı.tFakultes.SingleOrDefault(fakulte => fakulte.fakulteID == guncel_id);
            guncel_fakulte.fakulteID = Int16.Parse(textBox2.Text);
            guncel_fakulte.fakulteAd = textBox1.Text;
            veriTabanı.SaveChanges();

            dataGridView1.DataSource = veriTabanı.tFakultes.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void button3_Click(object sender, EventArgs e)//Temizle button
        {
            textBox1.Clear();
            textBox2.Clear();

        }

        private void button4_Click(object sender, EventArgs e)//Sil button
        {
            Model1 veriTabani = new Model1();

            //int sil_id = (int)dataGridView1.CurrentRow.Cells["FakulteID"].Value;

            int sil_id = Int16.Parse(textBox2.Text);
            tFakulte sil_fakulte = veriTabani.tFakultes.SingleOrDefault(fakulte => fakulte.fakulteID == sil_id);
            veriTabani.tFakultes.Remove(sil_fakulte);
            veriTabani.SaveChanges();

            dataGridView1.DataSource = veriTabani.tFakultes.ToList();

            textBox1.Clear();
            textBox2.Clear();

        }

        private void Form6_Load(object sender, EventArgs e)
        {
            Model1 veriTabanı = new Model1();

            dataGridView1.DataSource = veriTabanı.tFakultes.ToList();

        } 
    }
}

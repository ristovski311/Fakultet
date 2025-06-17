namespace VozaciLab
{
    partial class Vozac
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
            this.gpbOsnovniPodaci = new System.Windows.Forms.GroupBox();
            this.lblMesto = new System.Windows.Forms.Label();
            this.lblBrojDozvole = new System.Windows.Forms.Label();
            this.txbMesto = new System.Windows.Forms.TextBox();
            this.txbBrojDozvole = new System.Windows.Forms.TextBox();
            this.lblRodjenje = new System.Windows.Forms.Label();
            this.lblVozackaOd = new System.Windows.Forms.Label();
            this.lblVozackaDo = new System.Windows.Forms.Label();
            this.dtpVozackaDo = new System.Windows.Forms.DateTimePicker();
            this.dtpVozackaOd = new System.Windows.Forms.DateTimePicker();
            this.dtpRodjenje = new System.Windows.Forms.DateTimePicker();
            this.lblPrezime = new System.Windows.Forms.Label();
            this.lblIme = new System.Windows.Forms.Label();
            this.txbPrezime = new System.Windows.Forms.TextBox();
            this.txbIme = new System.Windows.Forms.TextBox();
            this.cmbPol = new System.Windows.Forms.ComboBox();
            this.btnDodajSliku = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.lblPol = new System.Windows.Forms.Label();
            this.gpbKategorija = new System.Windows.Forms.GroupBox();
            this.btnObrisiKategoriju = new System.Windows.Forms.Button();
            this.btnDodajKategoriju = new System.Windows.Forms.Button();
            this.dgvKategorije = new System.Windows.Forms.DataGridView();
            this.gpbZabrane = new System.Windows.Forms.GroupBox();
            this.btnObrisiZabranu = new System.Windows.Forms.Button();
            this.btnDodajZabranu = new System.Windows.Forms.Button();
            this.dgvZabrane = new System.Windows.Forms.DataGridView();
            this.btnProsledi = new System.Windows.Forms.Button();
            this.btnZatvori = new System.Windows.Forms.Button();
            this.gpbOsnovniPodaci.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.gpbKategorija.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvKategorije)).BeginInit();
            this.gpbZabrane.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvZabrane)).BeginInit();
            this.SuspendLayout();
            // 
            // gpbOsnovniPodaci
            // 
            this.gpbOsnovniPodaci.Controls.Add(this.lblMesto);
            this.gpbOsnovniPodaci.Controls.Add(this.lblBrojDozvole);
            this.gpbOsnovniPodaci.Controls.Add(this.txbMesto);
            this.gpbOsnovniPodaci.Controls.Add(this.txbBrojDozvole);
            this.gpbOsnovniPodaci.Controls.Add(this.lblRodjenje);
            this.gpbOsnovniPodaci.Controls.Add(this.lblVozackaOd);
            this.gpbOsnovniPodaci.Controls.Add(this.lblVozackaDo);
            this.gpbOsnovniPodaci.Controls.Add(this.dtpVozackaDo);
            this.gpbOsnovniPodaci.Controls.Add(this.dtpVozackaOd);
            this.gpbOsnovniPodaci.Controls.Add(this.dtpRodjenje);
            this.gpbOsnovniPodaci.Controls.Add(this.lblPrezime);
            this.gpbOsnovniPodaci.Controls.Add(this.lblIme);
            this.gpbOsnovniPodaci.Controls.Add(this.txbPrezime);
            this.gpbOsnovniPodaci.Controls.Add(this.txbIme);
            this.gpbOsnovniPodaci.Controls.Add(this.cmbPol);
            this.gpbOsnovniPodaci.Controls.Add(this.btnDodajSliku);
            this.gpbOsnovniPodaci.Controls.Add(this.pictureBox1);
            this.gpbOsnovniPodaci.Controls.Add(this.lblPol);
            this.gpbOsnovniPodaci.Location = new System.Drawing.Point(12, 12);
            this.gpbOsnovniPodaci.Name = "gpbOsnovniPodaci";
            this.gpbOsnovniPodaci.Size = new System.Drawing.Size(527, 256);
            this.gpbOsnovniPodaci.TabIndex = 0;
            this.gpbOsnovniPodaci.TabStop = false;
            this.gpbOsnovniPodaci.Text = "Osnovni podaci";
            // 
            // lblMesto
            // 
            this.lblMesto.AutoSize = true;
            this.lblMesto.Location = new System.Drawing.Point(37, 189);
            this.lblMesto.Name = "lblMesto";
            this.lblMesto.Size = new System.Drawing.Size(108, 16);
            this.lblMesto.TabIndex = 15;
            this.lblMesto.Text = "Mesto izdavanja:";
            // 
            // lblBrojDozvole
            // 
            this.lblBrojDozvole.AutoSize = true;
            this.lblBrojDozvole.Location = new System.Drawing.Point(10, 164);
            this.lblBrojDozvole.Name = "lblBrojDozvole";
            this.lblBrojDozvole.Size = new System.Drawing.Size(131, 16);
            this.lblBrojDozvole.TabIndex = 14;
            this.lblBrojDozvole.Text = "Br. vozacke dozvole:";
            // 
            // txbMesto
            // 
            this.txbMesto.Location = new System.Drawing.Point(153, 189);
            this.txbMesto.Name = "txbMesto";
            this.txbMesto.Size = new System.Drawing.Size(170, 22);
            this.txbMesto.TabIndex = 6;
            this.txbMesto.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txbMesto_KeyPress);
            this.txbMesto.Leave += new System.EventHandler(this.txbMesto_Leave);
            // 
            // txbBrojDozvole
            // 
            this.txbBrojDozvole.Location = new System.Drawing.Point(153, 161);
            this.txbBrojDozvole.Name = "txbBrojDozvole";
            this.txbBrojDozvole.Size = new System.Drawing.Size(170, 22);
            this.txbBrojDozvole.TabIndex = 5;
            this.txbBrojDozvole.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txbBrojDozvole_KeyPress);
            // 
            // lblRodjenje
            // 
            this.lblRodjenje.AutoSize = true;
            this.lblRodjenje.Location = new System.Drawing.Point(44, 83);
            this.lblRodjenje.Name = "lblRodjenje";
            this.lblRodjenje.Size = new System.Drawing.Size(101, 16);
            this.lblRodjenje.TabIndex = 11;
            this.lblRodjenje.Text = "Datum rodjenja:";
            // 
            // lblVozackaOd
            // 
            this.lblVozackaOd.AutoSize = true;
            this.lblVozackaOd.Location = new System.Drawing.Point(16, 110);
            this.lblVozackaOd.Name = "lblVozackaOd";
            this.lblVozackaOd.Size = new System.Drawing.Size(129, 16);
            this.lblVozackaOd.TabIndex = 12;
            this.lblVozackaOd.Text = "Vazenje dozvole od:";
            // 
            // lblVozackaDo
            // 
            this.lblVozackaDo.AutoSize = true;
            this.lblVozackaDo.Location = new System.Drawing.Point(115, 138);
            this.lblVozackaDo.Name = "lblVozackaDo";
            this.lblVozackaDo.Size = new System.Drawing.Size(26, 16);
            this.lblVozackaDo.TabIndex = 13;
            this.lblVozackaDo.Text = "do:";
            // 
            // dtpVozackaDo
            // 
            this.dtpVozackaDo.CustomFormat = "dd.MM.yyyy.";
            this.dtpVozackaDo.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpVozackaDo.Location = new System.Drawing.Point(153, 133);
            this.dtpVozackaDo.Name = "dtpVozackaDo";
            this.dtpVozackaDo.Size = new System.Drawing.Size(170, 22);
            this.dtpVozackaDo.TabIndex = 4;
            // 
            // dtpVozackaOd
            // 
            this.dtpVozackaOd.CustomFormat = "dd.MM.yyyy.";
            this.dtpVozackaOd.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpVozackaOd.Location = new System.Drawing.Point(153, 105);
            this.dtpVozackaOd.Name = "dtpVozackaOd";
            this.dtpVozackaOd.Size = new System.Drawing.Size(170, 22);
            this.dtpVozackaOd.TabIndex = 3;
            // 
            // dtpRodjenje
            // 
            this.dtpRodjenje.CustomFormat = "dd.MM.yyyy.";
            this.dtpRodjenje.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dtpRodjenje.Location = new System.Drawing.Point(153, 77);
            this.dtpRodjenje.Name = "dtpRodjenje";
            this.dtpRodjenje.Size = new System.Drawing.Size(170, 22);
            this.dtpRodjenje.TabIndex = 2;
            // 
            // lblPrezime
            // 
            this.lblPrezime.AutoSize = true;
            this.lblPrezime.Location = new System.Drawing.Point(88, 52);
            this.lblPrezime.Name = "lblPrezime";
            this.lblPrezime.Size = new System.Drawing.Size(59, 16);
            this.lblPrezime.TabIndex = 10;
            this.lblPrezime.Text = "Prezime:";
            // 
            // lblIme
            // 
            this.lblIme.AutoSize = true;
            this.lblIme.Location = new System.Drawing.Point(115, 24);
            this.lblIme.Name = "lblIme";
            this.lblIme.Size = new System.Drawing.Size(32, 16);
            this.lblIme.TabIndex = 9;
            this.lblIme.Text = "Ime:";
            // 
            // txbPrezime
            // 
            this.txbPrezime.Location = new System.Drawing.Point(153, 49);
            this.txbPrezime.Name = "txbPrezime";
            this.txbPrezime.Size = new System.Drawing.Size(170, 22);
            this.txbPrezime.TabIndex = 1;
            this.txbPrezime.TextChanged += new System.EventHandler(this.txbPrezime_TextChanged);
            this.txbPrezime.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txbPrezime_KeyPress);
            this.txbPrezime.Leave += new System.EventHandler(this.txbPrezime_Leave);
            // 
            // txbIme
            // 
            this.txbIme.Location = new System.Drawing.Point(153, 21);
            this.txbIme.Name = "txbIme";
            this.txbIme.Size = new System.Drawing.Size(170, 22);
            this.txbIme.TabIndex = 0;
            this.txbIme.TextChanged += new System.EventHandler(this.txbIme_TextChanged);
            this.txbIme.KeyPress += new System.Windows.Forms.KeyPressEventHandler(this.txbIme_KeyPress);
            this.txbIme.Leave += new System.EventHandler(this.txbIme_Leave);
            // 
            // cmbPol
            // 
            this.cmbPol.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbPol.FormattingEnabled = true;
            this.cmbPol.Items.AddRange(new object[] {
            "M",
            "Z"});
            this.cmbPol.Location = new System.Drawing.Point(153, 217);
            this.cmbPol.Name = "cmbPol";
            this.cmbPol.Size = new System.Drawing.Size(170, 24);
            this.cmbPol.TabIndex = 7;
            // 
            // btnDodajSliku
            // 
            this.btnDodajSliku.Location = new System.Drawing.Point(357, 177);
            this.btnDodajSliku.Name = "btnDodajSliku";
            this.btnDodajSliku.Size = new System.Drawing.Size(164, 44);
            this.btnDodajSliku.TabIndex = 8;
            this.btnDodajSliku.Text = "Dodaj sliku";
            this.btnDodajSliku.UseVisualStyleBackColor = true;
            this.btnDodajSliku.Click += new System.EventHandler(this.btnDodajSliku_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(357, 21);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(164, 150);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // lblPol
            // 
            this.lblPol.AutoSize = true;
            this.lblPol.Location = new System.Drawing.Point(111, 220);
            this.lblPol.Name = "lblPol";
            this.lblPol.Size = new System.Drawing.Size(30, 16);
            this.lblPol.TabIndex = 16;
            this.lblPol.Text = "Pol:";
            // 
            // gpbKategorija
            // 
            this.gpbKategorija.Controls.Add(this.btnObrisiKategoriju);
            this.gpbKategorija.Controls.Add(this.btnDodajKategoriju);
            this.gpbKategorija.Controls.Add(this.dgvKategorije);
            this.gpbKategorija.Location = new System.Drawing.Point(12, 274);
            this.gpbKategorija.Name = "gpbKategorija";
            this.gpbKategorija.Size = new System.Drawing.Size(527, 211);
            this.gpbKategorija.TabIndex = 1;
            this.gpbKategorija.TabStop = false;
            this.gpbKategorija.Text = "Kategorija";
            // 
            // btnObrisiKategoriju
            // 
            this.btnObrisiKategoriju.Image = global::VozaciLab.Properties.Resources.delete;
            this.btnObrisiKategoriju.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnObrisiKategoriju.Location = new System.Drawing.Point(366, 144);
            this.btnObrisiKategoriju.Name = "btnObrisiKategoriju";
            this.btnObrisiKategoriju.Size = new System.Drawing.Size(155, 61);
            this.btnObrisiKategoriju.TabIndex = 1;
            this.btnObrisiKategoriju.Text = "Obrisi";
            this.btnObrisiKategoriju.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnObrisiKategoriju.UseVisualStyleBackColor = true;
            this.btnObrisiKategoriju.Click += new System.EventHandler(this.btnObrisiKategoriju_Click);
            // 
            // btnDodajKategoriju
            // 
            this.btnDodajKategoriju.Image = global::VozaciLab.Properties.Resources.add;
            this.btnDodajKategoriju.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnDodajKategoriju.Location = new System.Drawing.Point(6, 144);
            this.btnDodajKategoriju.Name = "btnDodajKategoriju";
            this.btnDodajKategoriju.Size = new System.Drawing.Size(155, 61);
            this.btnDodajKategoriju.TabIndex = 0;
            this.btnDodajKategoriju.Text = "Dodaj";
            this.btnDodajKategoriju.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnDodajKategoriju.UseVisualStyleBackColor = true;
            this.btnDodajKategoriju.Click += new System.EventHandler(this.btnDodajKategoriju_Click);
            // 
            // dgvKategorije
            // 
            this.dgvKategorije.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvKategorije.Location = new System.Drawing.Point(6, 21);
            this.dgvKategorije.Name = "dgvKategorije";
            this.dgvKategorije.ReadOnly = true;
            this.dgvKategorije.RowHeadersWidth = 51;
            this.dgvKategorije.RowTemplate.Height = 24;
            this.dgvKategorije.Size = new System.Drawing.Size(515, 117);
            this.dgvKategorije.TabIndex = 2;
            // 
            // gpbZabrane
            // 
            this.gpbZabrane.Controls.Add(this.btnObrisiZabranu);
            this.gpbZabrane.Controls.Add(this.btnDodajZabranu);
            this.gpbZabrane.Controls.Add(this.dgvZabrane);
            this.gpbZabrane.Location = new System.Drawing.Point(12, 491);
            this.gpbZabrane.Name = "gpbZabrane";
            this.gpbZabrane.Size = new System.Drawing.Size(527, 228);
            this.gpbZabrane.TabIndex = 2;
            this.gpbZabrane.TabStop = false;
            this.gpbZabrane.Text = "Zabrana upravljanja";
            // 
            // btnObrisiZabranu
            // 
            this.btnObrisiZabranu.Image = global::VozaciLab.Properties.Resources.delete;
            this.btnObrisiZabranu.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnObrisiZabranu.Location = new System.Drawing.Point(366, 161);
            this.btnObrisiZabranu.Name = "btnObrisiZabranu";
            this.btnObrisiZabranu.Size = new System.Drawing.Size(155, 61);
            this.btnObrisiZabranu.TabIndex = 1;
            this.btnObrisiZabranu.Text = "Obrisi";
            this.btnObrisiZabranu.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnObrisiZabranu.UseVisualStyleBackColor = true;
            this.btnObrisiZabranu.Click += new System.EventHandler(this.btnObrisiZabranu_Click);
            // 
            // btnDodajZabranu
            // 
            this.btnDodajZabranu.Image = global::VozaciLab.Properties.Resources.add;
            this.btnDodajZabranu.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnDodajZabranu.Location = new System.Drawing.Point(6, 161);
            this.btnDodajZabranu.Name = "btnDodajZabranu";
            this.btnDodajZabranu.Size = new System.Drawing.Size(155, 61);
            this.btnDodajZabranu.TabIndex = 0;
            this.btnDodajZabranu.Text = "Dodaj";
            this.btnDodajZabranu.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnDodajZabranu.UseVisualStyleBackColor = true;
            this.btnDodajZabranu.Click += new System.EventHandler(this.btnDodajZabranu_Click);
            // 
            // dgvZabrane
            // 
            this.dgvZabrane.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvZabrane.Location = new System.Drawing.Point(6, 21);
            this.dgvZabrane.Name = "dgvZabrane";
            this.dgvZabrane.ReadOnly = true;
            this.dgvZabrane.RowHeadersWidth = 51;
            this.dgvZabrane.RowTemplate.Height = 24;
            this.dgvZabrane.Size = new System.Drawing.Size(515, 130);
            this.dgvZabrane.TabIndex = 2;
            // 
            // btnProsledi
            // 
            this.btnProsledi.Location = new System.Drawing.Point(12, 725);
            this.btnProsledi.Name = "btnProsledi";
            this.btnProsledi.Size = new System.Drawing.Size(170, 40);
            this.btnProsledi.TabIndex = 3;
            this.btnProsledi.Text = "Prosledi";
            this.btnProsledi.UseVisualStyleBackColor = true;
            this.btnProsledi.Click += new System.EventHandler(this.btnProsledi_Click);
            // 
            // btnZatvori
            // 
            this.btnZatvori.Location = new System.Drawing.Point(369, 725);
            this.btnZatvori.Name = "btnZatvori";
            this.btnZatvori.Size = new System.Drawing.Size(170, 40);
            this.btnZatvori.TabIndex = 4;
            this.btnZatvori.Text = "Zatvori";
            this.btnZatvori.UseVisualStyleBackColor = true;
            this.btnZatvori.Click += new System.EventHandler(this.btnZatvori_Click);
            // 
            // Vozac
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(551, 777);
            this.Controls.Add(this.btnZatvori);
            this.Controls.Add(this.btnProsledi);
            this.Controls.Add(this.gpbZabrane);
            this.Controls.Add(this.gpbKategorija);
            this.Controls.Add(this.gpbOsnovniPodaci);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(569, 824);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(569, 824);
            this.Name = "Vozac";
            this.Text = "Vozac";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Vozac_FormClosing);
            this.Load += new System.EventHandler(this.Vozac_Load);
            this.gpbOsnovniPodaci.ResumeLayout(false);
            this.gpbOsnovniPodaci.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.gpbKategorija.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvKategorije)).EndInit();
            this.gpbZabrane.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvZabrane)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox gpbOsnovniPodaci;
        private System.Windows.Forms.GroupBox gpbKategorija;
        private System.Windows.Forms.GroupBox gpbZabrane;
        private System.Windows.Forms.DataGridView dgvKategorije;
        private System.Windows.Forms.Button btnObrisiKategoriju;
        private System.Windows.Forms.Button btnDodajKategoriju;
        private System.Windows.Forms.Button btnObrisiZabranu;
        private System.Windows.Forms.Button btnDodajZabranu;
        private System.Windows.Forms.DataGridView dgvZabrane;
        private System.Windows.Forms.Label lblPol;
        private System.Windows.Forms.ComboBox cmbPol;
        private System.Windows.Forms.Button btnDodajSliku;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.DateTimePicker dtpVozackaDo;
        private System.Windows.Forms.DateTimePicker dtpVozackaOd;
        private System.Windows.Forms.DateTimePicker dtpRodjenje;
        private System.Windows.Forms.Label lblPrezime;
        private System.Windows.Forms.Label lblIme;
        private System.Windows.Forms.TextBox txbPrezime;
        private System.Windows.Forms.TextBox txbIme;
        private System.Windows.Forms.Label lblRodjenje;
        private System.Windows.Forms.Label lblVozackaOd;
        private System.Windows.Forms.Label lblVozackaDo;
        private System.Windows.Forms.Label lblMesto;
        private System.Windows.Forms.Label lblBrojDozvole;
        private System.Windows.Forms.TextBox txbMesto;
        private System.Windows.Forms.TextBox txbBrojDozvole;
        private System.Windows.Forms.Button btnProsledi;
        private System.Windows.Forms.Button btnZatvori;
    }
}
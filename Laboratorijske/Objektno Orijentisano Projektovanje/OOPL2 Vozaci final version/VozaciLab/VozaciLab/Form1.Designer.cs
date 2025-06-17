namespace VozaciLab
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            this.lblVreme = new System.Windows.Forms.Label();
            this.tmrVreme = new System.Windows.Forms.Timer(this.components);
            this.grbMainGroup = new System.Windows.Forms.GroupBox();
            this.dgvListaVozaca = new System.Windows.Forms.DataGridView();
            this.btnObrisi = new System.Windows.Forms.Button();
            this.btnIzmeni = new System.Windows.Forms.Button();
            this.btnDodaj = new System.Windows.Forms.Button();
            this.btnSort = new System.Windows.Forms.Button();
            this.cmbSort = new System.Windows.Forms.ComboBox();
            this.grbMainGroup.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dgvListaVozaca)).BeginInit();
            this.SuspendLayout();
            // 
            // lblVreme
            // 
            this.lblVreme.AutoSize = true;
            this.lblVreme.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.lblVreme.Font = new System.Drawing.Font("Segoe UI", 10.8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblVreme.Location = new System.Drawing.Point(18, 18);
            this.lblVreme.Name = "lblVreme";
            this.lblVreme.Size = new System.Drawing.Size(64, 27);
            this.lblVreme.TabIndex = 3;
            this.lblVreme.Text = "Vreme";
            // 
            // tmrVreme
            // 
            this.tmrVreme.Tick += new System.EventHandler(this.tmrVreme_Tick);
            // 
            // grbMainGroup
            // 
            this.grbMainGroup.Controls.Add(this.dgvListaVozaca);
            this.grbMainGroup.Controls.Add(this.btnObrisi);
            this.grbMainGroup.Controls.Add(this.btnIzmeni);
            this.grbMainGroup.Controls.Add(this.btnDodaj);
            this.grbMainGroup.Location = new System.Drawing.Point(12, 64);
            this.grbMainGroup.Name = "grbMainGroup";
            this.grbMainGroup.Size = new System.Drawing.Size(776, 374);
            this.grbMainGroup.TabIndex = 0;
            this.grbMainGroup.TabStop = false;
            this.grbMainGroup.Text = "Lista vozaca";
            // 
            // dgvListaVozaca
            // 
            this.dgvListaVozaca.BackgroundColor = System.Drawing.Color.White;
            this.dgvListaVozaca.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvListaVozaca.Location = new System.Drawing.Point(6, 21);
            this.dgvListaVozaca.Name = "dgvListaVozaca";
            this.dgvListaVozaca.ReadOnly = true;
            this.dgvListaVozaca.RowHeadersWidth = 51;
            this.dgvListaVozaca.RowTemplate.Height = 24;
            this.dgvListaVozaca.Size = new System.Drawing.Size(764, 276);
            this.dgvListaVozaca.TabIndex = 3;
            // 
            // btnObrisi
            // 
            this.btnObrisi.Image = global::VozaciLab.Properties.Resources.delete;
            this.btnObrisi.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnObrisi.Location = new System.Drawing.Point(602, 303);
            this.btnObrisi.Name = "btnObrisi";
            this.btnObrisi.Size = new System.Drawing.Size(168, 71);
            this.btnObrisi.TabIndex = 2;
            this.btnObrisi.Text = "Obrisi";
            this.btnObrisi.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnObrisi.UseVisualStyleBackColor = true;
            this.btnObrisi.Click += new System.EventHandler(this.btnObrisi_Click);
            // 
            // btnIzmeni
            // 
            this.btnIzmeni.Image = global::VozaciLab.Properties.Resources.edit;
            this.btnIzmeni.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnIzmeni.Location = new System.Drawing.Point(157, 303);
            this.btnIzmeni.Name = "btnIzmeni";
            this.btnIzmeni.Size = new System.Drawing.Size(155, 65);
            this.btnIzmeni.TabIndex = 1;
            this.btnIzmeni.Text = "Izmeni";
            this.btnIzmeni.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnIzmeni.UseVisualStyleBackColor = true;
            this.btnIzmeni.Click += new System.EventHandler(this.btnIzmeni_Click);
            // 
            // btnDodaj
            // 
            this.btnDodaj.Image = global::VozaciLab.Properties.Resources.add;
            this.btnDodaj.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.btnDodaj.Location = new System.Drawing.Point(6, 303);
            this.btnDodaj.Name = "btnDodaj";
            this.btnDodaj.Size = new System.Drawing.Size(145, 65);
            this.btnDodaj.TabIndex = 0;
            this.btnDodaj.Text = "Dodaj";
            this.btnDodaj.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.btnDodaj.UseVisualStyleBackColor = true;
            this.btnDodaj.Click += new System.EventHandler(this.btnDodaj_Click);
            // 
            // btnSort
            // 
            this.btnSort.Location = new System.Drawing.Point(458, 12);
            this.btnSort.Name = "btnSort";
            this.btnSort.Size = new System.Drawing.Size(119, 50);
            this.btnSort.TabIndex = 1;
            this.btnSort.Text = "Sortiraj";
            this.btnSort.UseVisualStyleBackColor = true;
            this.btnSort.Click += new System.EventHandler(this.btnSort_Click);
            // 
            // cmbSort
            // 
            this.cmbSort.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbSort.FormattingEnabled = true;
            this.cmbSort.Items.AddRange(new object[] {
            "Broj vozacke dozvole",
            "Ime",
            "Prezime"});
            this.cmbSort.Location = new System.Drawing.Point(583, 22);
            this.cmbSort.Name = "cmbSort";
            this.cmbSort.Size = new System.Drawing.Size(199, 24);
            this.cmbSort.TabIndex = 2;
            this.cmbSort.SelectedValueChanged += new System.EventHandler(this.cmbSort_SelectedValueChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.cmbSort);
            this.Controls.Add(this.btnSort);
            this.Controls.Add(this.grbMainGroup);
            this.Controls.Add(this.lblVreme);
            this.MaximizeBox = false;
            this.MaximumSize = new System.Drawing.Size(818, 497);
            this.MinimizeBox = false;
            this.MinimumSize = new System.Drawing.Size(818, 497);
            this.Name = "Form1";
            this.Text = "Lista Vozaca";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.Form1_FormClosing);
            this.Load += new System.EventHandler(this.Form1_Load);
            this.grbMainGroup.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dgvListaVozaca)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblVreme;
        private System.Windows.Forms.Timer tmrVreme;
        private System.Windows.Forms.GroupBox grbMainGroup;
        private System.Windows.Forms.Button btnSort;
        private System.Windows.Forms.ComboBox cmbSort;
        private System.Windows.Forms.Button btnDodaj;
        private System.Windows.Forms.Button btnIzmeni;
        private System.Windows.Forms.Button btnObrisi;
        private System.Windows.Forms.DataGridView dgvListaVozaca;
    }
}


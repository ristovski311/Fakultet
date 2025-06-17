using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace OOPCalculator
{
    public partial class Form1 : Form
    {
        private bool isDateShown = false;

        private void ClearDate()
        {
            if (isDateShown)
            {
                lblResult.Text = "0";
                isDateShown = false;
                btnAdd.Enabled = true;
                btnSub.Enabled = true;
                btnMul.Enabled = true;
                btnDiv.Enabled = true;
                btnChngSign.Enabled = true;
                btnDot.Enabled = true;
                btnEq.Enabled = true;
            }
        }

        public Form1()
        {
            InitializeComponent();
        }

        //Form

        private void Form1_Load(object sender, EventArgs e)
        {
            lblResult.Text = "0";
        }

        private void Form1_Leave(object sender, EventArgs e)
        {

        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {

            DialogResult dgres = MessageBox.Show("Are you sure you want to exit?", "EXIT?", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (dgres == DialogResult.Cancel)
            {
                e.Cancel = true;
            }

        }

        //Buttons

        private void btnDate_Click(object sender, EventArgs e)
        {
            isDateShown = true;
            DateTime curTime = DateTime.Now;
            lblResult.Text = curTime.ShowCurrentTime();
            btnAdd.Enabled = false;
            btnSub.Enabled = false;
            btnMul.Enabled = false;
            btnDiv.Enabled = false;
            btnChngSign.Enabled = false;
            btnDot.Enabled = false;
            btnEq.Enabled = false;


        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = "0";
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        //Number Buttons

        private void btnNum0_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('0');
        }

        private void btnNum1_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('1');
        }

        private void btnNum2_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('2');
        }

        private void btnNum3_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('3');
        }

        private void btnNum4_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('4');
        }

        private void btnNum5_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('5');
        }

        private void btnNum6_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('6');
        }

        private void btnNum7_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('7');
        }

        private void btnNum8_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('8');
        }

        private void btnNum9_Click(object sender, EventArgs e)
        {
            ClearDate();
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('9');
        }

        private void bntDot_Click(object sender, EventArgs e)
        {
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('.');
        }

        private void btnAdd_Click(object sender, EventArgs e)
        {
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('+');
        }

        private void btnSub_Click(object sender, EventArgs e)
        {
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('-');
        }

        private void btnMul_Click(object sender, EventArgs e)
        {
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('*');
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {
            lblResult.Text = lblResult.Text.AddCharacterToCalculator('/');
        }

        private void btnChngSign_Click(object sender, EventArgs e)
        {
            if (lblResult.Text.IsLastSign())
            { 
                MessageBox.Show("Nothing to change the sign to!");
                return;
            }
            try
            {
                double num = Double.Parse(lblResult.Text);
                num = num - 2 * num;
                lblResult.Text = num.ToString();
            }
            catch (Exception ex)
            {
                char[] temp = lblResult.Text.ToCharArray();
                int i = temp.Length-1;
                while (!temp[i].IsSign())
                {
                    i--;
                }
                if (temp[i-1] == '(')
                {
                    lblResult.Text = lblResult.Text.Remove(i-1,2);
                    lblResult.Text = lblResult.Text.Remove(lblResult.Text.Length-1,1);
                }
                else
                {
                    lblResult.Text = lblResult.Text.Insert(i+1, "(-");
                    lblResult.Text += ")";
                }
            }
            
        }

        private void btnEq_Click(object sender, EventArgs e)
        {
            if(lblResult.Text.IsLastSign())
            {
                MessageBox.Show("Invalid format!");
                return;
            }
            double res;
            string[] splits; 
            if(lblResult.Text.IndexOf("-") == 0)
            {
                lblResult.Text = lblResult.Text.Substring(1);
                splits = lblResult.Text.Split('+', '-', '*', '/', '(', ')');
                res = Double.Parse(splits[0]) * (-1);
            }
            else
            {
                splits = lblResult.Text.Split('+', '-', '*', '/', '(', ')');
                res = Double.Parse(splits[0]);
            }
            int i = 1;
            int j = 0;
            while (j != lblResult.Text.Length)
            {
                switch (lblResult.Text.ToCharArray()[j])
                {
                    case '+':
                        {
                            if (lblResult.Text.ToCharArray()[j+1] == '(')
                            {
                                res += (Double.Parse(splits[i+2]) * (-1));
                                i += 4;
                                j += 3;
                            }
                            else
                            {
                                res += Double.Parse(splits[i]);
                                i++;
                            }
                        }
                        break;
                    case '-':
                        {
                            if (lblResult.Text.ToCharArray()[j + 1] == '(')
                            {
                                res -= (Double.Parse(splits[i + 2]) * (-1));
                                i += 4;
                                j += 3;
                            }
                            else
                            {
                                res -= Double.Parse(splits[i]);
                                i++;
                            }
                        }
                        break;
                    case '*':
                        {
                            if (lblResult.Text.ToCharArray()[j + 1] == '(')
                            {
                                res *= (Double.Parse(splits[i + 2]) * (-1));
                                i += 4;
                                j += 3;
                            }
                            else
                            {
                                res *= Double.Parse(splits[i]);
                                i++;
                            }
                        }
                        break;
                    case '/':
                        {
                            if (lblResult.Text.ToCharArray()[j + 1] == '(')
                            {
                                res /= (Double.Parse(splits[i + 2]) * (-1));
                                i += 4;
                                j += 3;
                            }
                            else
                            {
                                res /= Double.Parse(splits[i]);
                                i++;
                            }
                            
                        }
                        break;
                }
                j++;
            }
            lblResult.Text = res.ToString();
            MessageBox.Show("Calculated the result!", "Result", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        private void btnToBinary_Click(object sender, EventArgs e)
        {
            btnEq_Click(sender, e);
            string result = "";
            string[] numbers = lblResult.Text.Split('.');
            foreach(string number in numbers)
            {
                string binary = Convert.ToString(Int64.Parse(number), 2);
                result += binary;
                result += ".";
            }
            lblResult.Text = result.Substring(0, result.Length-1);
        }
    }
}

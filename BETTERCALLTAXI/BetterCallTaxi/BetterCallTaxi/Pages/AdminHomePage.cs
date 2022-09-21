using BetterCallTaxi.Models;
using BetterCallTaxi.Pages;
using BetterCallTaxi.Reports.Customers;
using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BetterCallTaxi
{
    class Admin_Home_Page : Form
    {
        private ListView Admin_List_View;
        private System.ComponentModel.IContainer components;
        private MenuStrip menuStrip1;
        private ToolStripMenuItem adminToolStripMenuItem;
        private ToolStripMenuItem tableReportsToolStripMenuItem;
        private ToolStripMenuItem customersToolStripMenuItem;
        private ToolStripMenuItem driversToolStripMenuItem;
        private ToolStripMenuItem ordersToolStripMenuItem;
        private ToolStripMenuItem carsToolStripMenuItem;
        private ToolStripMenuItem manufacturersToolStripMenuItem;
        private ToolStripMenuItem orderRequestsToolStripMenuItem;
        private ToolStripMenuItem customReportsToolStripMenuItem;
        private ToolStripMenuItem ordersBeforeDateToolStripMenuItem;
        private ToolStripMenuItem profileToolStripMenuItem;
        private ToolStripMenuItem viewProfileToolStripMenuItem;
        private ToolStripMenuItem logoutToolStripMenuItem;
        Customer recCustomer;

        public Admin_Home_Page(Customer recCustomer)
        {
            InitializeComponent();
            this.Location = GlobalConstants.START_POINT;
            this.recCustomer = recCustomer;    
            this.Admin_List_View.View = View.Details;
        }

        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Admin_Home_Page));
            this.Admin_List_View = new System.Windows.Forms.ListView();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.adminToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tableReportsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.customersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.driversToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ordersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.carsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.manufacturersToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.orderRequestsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.customReportsToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ordersBeforeDateToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.profileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.viewProfileToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.logoutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // Admin_List_View
            // 
            this.Admin_List_View.FullRowSelect = true;
            this.Admin_List_View.GridLines = true;
            this.Admin_List_View.HideSelection = false;
            this.Admin_List_View.Location = new System.Drawing.Point(0, 23);
            this.Admin_List_View.MultiSelect = false;
            this.Admin_List_View.Name = "Admin_List_View";
            this.Admin_List_View.Size = new System.Drawing.Size(958, 624);
            this.Admin_List_View.TabIndex = 4;
            this.Admin_List_View.UseCompatibleStateImageBehavior = false;
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.adminToolStripMenuItem,
            this.profileToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(958, 28);
            this.menuStrip1.TabIndex = 5;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // adminToolStripMenuItem
            // 
            this.adminToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.tableReportsToolStripMenuItem,
            this.customReportsToolStripMenuItem});
            this.adminToolStripMenuItem.Name = "adminToolStripMenuItem";
            this.adminToolStripMenuItem.Size = new System.Drawing.Size(65, 24);
            this.adminToolStripMenuItem.Text = "Admin";
            // 
            // tableReportsToolStripMenuItem
            // 
            this.tableReportsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.customersToolStripMenuItem,
            this.driversToolStripMenuItem,
            this.ordersToolStripMenuItem,
            this.carsToolStripMenuItem,
            this.manufacturersToolStripMenuItem,
            this.orderRequestsToolStripMenuItem});
            this.tableReportsToolStripMenuItem.Name = "tableReportsToolStripMenuItem";
            this.tableReportsToolStripMenuItem.Size = new System.Drawing.Size(189, 26);
            this.tableReportsToolStripMenuItem.Text = "Table Reports";
            // 
            // customersToolStripMenuItem
            // 
            this.customersToolStripMenuItem.Name = "customersToolStripMenuItem";
            this.customersToolStripMenuItem.Size = new System.Drawing.Size(185, 26);
            this.customersToolStripMenuItem.Text = "Customers";
            this.customersToolStripMenuItem.Click += new System.EventHandler(this.customersToolStripMenuItem_Click);
            // 
            // driversToolStripMenuItem
            // 
            this.driversToolStripMenuItem.Name = "driversToolStripMenuItem";
            this.driversToolStripMenuItem.Size = new System.Drawing.Size(185, 26);
            this.driversToolStripMenuItem.Text = "Drivers";
            this.driversToolStripMenuItem.Click += new System.EventHandler(this.driversToolStripMenuItem_Click);
            // 
            // ordersToolStripMenuItem
            // 
            this.ordersToolStripMenuItem.Name = "ordersToolStripMenuItem";
            this.ordersToolStripMenuItem.Size = new System.Drawing.Size(185, 26);
            this.ordersToolStripMenuItem.Text = "Orders";
            this.ordersToolStripMenuItem.Click += new System.EventHandler(this.ordersToolStripMenuItem_Click);
            // 
            // carsToolStripMenuItem
            // 
            this.carsToolStripMenuItem.Name = "carsToolStripMenuItem";
            this.carsToolStripMenuItem.Size = new System.Drawing.Size(185, 26);
            this.carsToolStripMenuItem.Text = "Cars";
            this.carsToolStripMenuItem.Click += new System.EventHandler(this.carsToolStripMenuItem_Click);
            // 
            // manufacturersToolStripMenuItem
            // 
            this.manufacturersToolStripMenuItem.Name = "manufacturersToolStripMenuItem";
            this.manufacturersToolStripMenuItem.Size = new System.Drawing.Size(185, 26);
            this.manufacturersToolStripMenuItem.Text = "Manufacturers";
            this.manufacturersToolStripMenuItem.Click += new System.EventHandler(this.manufacturersToolStripMenuItem_Click);
            // 
            // orderRequestsToolStripMenuItem
            // 
            this.orderRequestsToolStripMenuItem.Name = "orderRequestsToolStripMenuItem";
            this.orderRequestsToolStripMenuItem.Size = new System.Drawing.Size(185, 26);
            this.orderRequestsToolStripMenuItem.Text = "Order Requests";
            this.orderRequestsToolStripMenuItem.Click += new System.EventHandler(this.orderRequestsToolStripMenuItem_Click);
            // 
            // customReportsToolStripMenuItem
            // 
            this.customReportsToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.ordersBeforeDateToolStripMenuItem});
            this.customReportsToolStripMenuItem.Name = "customReportsToolStripMenuItem";
            this.customReportsToolStripMenuItem.Size = new System.Drawing.Size(189, 26);
            this.customReportsToolStripMenuItem.Text = "Custom Reports";
            // 
            // ordersBeforeDateToolStripMenuItem
            // 
            this.ordersBeforeDateToolStripMenuItem.Name = "ordersBeforeDateToolStripMenuItem";
            this.ordersBeforeDateToolStripMenuItem.Size = new System.Drawing.Size(212, 26);
            this.ordersBeforeDateToolStripMenuItem.Text = "Orders Before Date";
            this.ordersBeforeDateToolStripMenuItem.Click += new System.EventHandler(this.ordersBeforeDateToolStripMenuItem_Click);
            // 
            // profileToolStripMenuItem
            // 
            this.profileToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.viewProfileToolStripMenuItem,
            this.logoutToolStripMenuItem});
            this.profileToolStripMenuItem.Name = "profileToolStripMenuItem";
            this.profileToolStripMenuItem.Size = new System.Drawing.Size(112, 24);
            this.profileToolStripMenuItem.Text = "Welcome, {0}!";
            // 
            // viewProfileToolStripMenuItem
            // 
            this.viewProfileToolStripMenuItem.Name = "viewProfileToolStripMenuItem";
            this.viewProfileToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.viewProfileToolStripMenuItem.Text = "View Profile";
            this.viewProfileToolStripMenuItem.Click += new System.EventHandler(this.viewProfileToolStripMenuItem_Click);
            // 
            // logoutToolStripMenuItem
            // 
            this.logoutToolStripMenuItem.Name = "logoutToolStripMenuItem";
            this.logoutToolStripMenuItem.Size = new System.Drawing.Size(181, 26);
            this.logoutToolStripMenuItem.Text = "Logout";
            this.logoutToolStripMenuItem.Click += new System.EventHandler(this.logoutToolStripMenuItem_Click);
            // 
            // Admin_Home_Page
            // 
            this.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("$this.BackgroundImage")));
            this.ClientSize = new System.Drawing.Size(958, 645);
            this.Controls.Add(this.Admin_List_View);
            this.Controls.Add(this.menuStrip1);
            this.ForeColor = System.Drawing.Color.Black;
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Admin_Home_Page";
            this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
            this.Text = "Better Call Taxi - Home";
            this.Load += new System.EventHandler(this.AdminHomePage_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }
        
        private void AdminHomePage_Load(object sender, EventArgs e)
        {
            this.profileToolStripMenuItem.Text = String.Format(profileToolStripMenuItem.Text, this.recCustomer.strName);
        }

        private void Logout_Admin_Button_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.Cancel;
            this.Close();
        }

        private void Profile_Admin_Button_Click(object sender, EventArgs e)
        {
            // Крием Home страницата
            this.Hide();

            // Показваме Profile страницата
            ProfileDialog oProfileDialog = new ProfileDialog(recCustomer);
            oProfileDialog.ShowDialog();

            // За всеки случай ако е променян потребителят, го взимаме наново от базата
            DatabaseManager oDataBaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader =
                oDataBaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_ID, this.recCustomer.nId));

            // Записваме си го при нас
            this.recCustomer = new Customer(oSqlDataReader);
            this.profileToolStripMenuItem.Text = String.Format(GlobalConstants.WELCOME_USER, this.recCustomer.strName);

            // Да не забравим да затворим след нас
            oSqlDataReader.Close();

            // Показваме обратно Home страницата
            this.Show();
        }

        private void PrepareListViewForOrdBfrDateReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0; 
            ColumnHeader[] oHeaderCols = new ColumnHeader[4];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ORDER_TIME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.CAR_REG_NUMBER;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.MANUFACTURER_NAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.TOTAL_ORDERS_COUNTS;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void PrepareListViewForCustomersReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0;
            ColumnHeader[] oHeaderCols = new ColumnHeader[5];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.USERNAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.FULL_NAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.UCN;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ROLE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 90;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ORDERS_MADE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 90;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void PrepareListViewForDriversReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0;
            ColumnHeader[] oHeaderCols = new ColumnHeader[5];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.FULL_NAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.COMPLETED_ORDERS;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.MONEY_MADE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.STATUS;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 90;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void PrepareListViewForCarsReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0;
            ColumnHeader[] oHeaderCols = new ColumnHeader[5];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.REG_NOMER;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 70;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.MANUFACTURER;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.SEATS;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.LUGAGE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 90;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.DRIVER_NAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void PrepareListViewForOrdersReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0;
            ColumnHeader[] oHeaderCols = new ColumnHeader[10];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.REG_NOMER;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 70;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.MANUFACTURER;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 85;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ADDRESS_FROM;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ADDRESS_TO;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 130;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ORD_TIME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.DRIVING_TIME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 75;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.DISTANCE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 70;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.FARE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 70;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.CUSTOMER_NAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.IS_DONE;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 70;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void PrepareListViewForManufacturersReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0;
            ColumnHeader[] oHeaderCols = new ColumnHeader[10];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.MANUFACTURER;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 135;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void PrepareListViewForOrdReqCustNamesReport()
        {
            this.Admin_List_View.Clear();
            int nCol = 0;
            ColumnHeader[] oHeaderCols = new ColumnHeader[10];
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.CUSTOMER_NAME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ADDRESS_FROM;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ADDRESS_TO;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]); nCol++;
            nCol++;
            oHeaderCols[nCol] = new ColumnHeader();
            oHeaderCols[nCol].Text = GlobalConstants.ORD_TIME;
            oHeaderCols[nCol].TextAlign = HorizontalAlignment.Left;
            oHeaderCols[nCol].Width = 120;
            this.Admin_List_View.Columns.Add(oHeaderCols[nCol]);
        }

        private void FillOrdBfrDateReportData(List<OrdersBeforeDateRow> oRows)
        {
            foreach(OrdersBeforeDateRow oRow in oRows)
            {
                this.Admin_List_View.Items.Add(new ListViewItem(new string[]{
                        oRow.dtOrdDate.ToString(GlobalConstants.DATE_FORMAT)
                      , oRow.strRegNomer
                      , oRow.strManufacturerName
                      , oRow.nOrdersCounts.ToString() }));
            }
        }

        private void FillCustomersReportData(List<Customer> oCustomers)
        {
            foreach (Customer recCust in oCustomers)
            {
                string strRole = GlobalConstants.UNKNOWN;
                switch (recCust.nRoleId)
                {
                    case (int)Customer.Roles.RoleAdministrator: strRole = GlobalConstants.ADMINISTRATOR; break;
                    case (int)Customer.Roles.RoleDriver: strRole = GlobalConstants.DRIVER; break;
                    case (int)Customer.Roles.RoleUser: strRole = GlobalConstants.USER; break;
                }
                this.Admin_List_View.Items.Add(new ListViewItem(new string[]{
                        recCust.strName
                      , recCust.strUsername
                      , recCust.strUcn
                      , strRole
                      , recCust.nOrdersMade.ToString()}));
            }
        }

        private void FillDriversAndNamesView(List<DriversAndNames> oDriversAndNames)
        {
            foreach (DriversAndNames oDriverAndName in oDriversAndNames)
            {
                this.Admin_List_View.Items.Add(new ListViewItem(new string[]{
                        oDriverAndName.strName
                      , oDriverAndName.recDriver.nCompletedOrders.ToString()
                      , oDriverAndName.recDriver.dMoneyMade.ToString()
                      , oDriverAndName.recDriver.bStatus ? GlobalConstants.DRIVER_AVAILABLE : GlobalConstants.DRIVER_BUSY }
                ));
            }
        }

        private void FillCarsAndOnwersView(List<CarsAndOwners> oCarsAndOwnersList)
        {
            foreach (CarsAndOwners oCarAndOwner in oCarsAndOwnersList)
            {
                this.Admin_List_View.Items.Add(new ListViewItem(new string[]{
                        oCarAndOwner.recCar.strRegNomer
                      , oCarAndOwner.strManufacturer
                      , oCarAndOwner.recCar.bySeats.ToString()
                      , oCarAndOwner.recCar.bLugage ? GlobalConstants.YES : GlobalConstants.NO
                      , oCarAndOwner.strDriver }
                ));
            }
        }

        private void FillOrdersViewModelsInListView(List<OrdersViewModel> oOrderViewModels)
        {
            foreach (OrdersViewModel oOrderViewModel in oOrderViewModels)
            {
                this.Admin_List_View.Items.Add(new ListViewItem(new string[]{
                        oOrderViewModel.strRegNomer
                      , oOrderViewModel.strManufacturer
                      , oOrderViewModel.recOrder.strAddressFrom
                      , oOrderViewModel.recOrder.strAddressTo
                      , oOrderViewModel.recOrder.dtOrdTime.ToString(GlobalConstants.DATE_FORMAT)
                      , oOrderViewModel.recOrder.tDrivingTime.ToString()
                      , oOrderViewModel.recOrder.dDistance.ToString()
                      , oOrderViewModel.recOrder.dFare.ToString()
                      , oOrderViewModel.strCustName
                      , oOrderViewModel.recOrder.GetOrderStatus() }
                ));
            }
        }

        private void FillManufacturersInListView(List<Manufacturer> oManufacturersList)
        {
            foreach (Manufacturer recManufacturer in oManufacturersList)
            {
                this.Admin_List_View.Items.Add(new ListViewItem(new string[]{ recManufacturer.strName }));
            }
        }

        private void FillOrdReqsCustNamesInListView(List<OrdReqCustName> oOrdReqsCustNamesList)
        {
            foreach (OrdReqCustName oOrdReqCustName in oOrdReqsCustNamesList)
            {
                this.Admin_List_View.Items.Add(new ListViewItem(new string[] {
                    oOrdReqCustName.strCustName
                    , oOrdReqCustName.strAddressFrom
                    , oOrdReqCustName.strAddressTo
                    , oOrdReqCustName.dtOrdTime.ToString(GlobalConstants.DATE_FORMAT) }));
            }
        }

        private void Orders_Before_Click(object sender, EventArgs e)
        {
            OrdersBeforeDateDialog oOrdBfrDateDlg = new OrdersBeforeDateDialog();
            DialogResult eDialogResult = oOrdBfrDateDlg.ShowDialog();

            if (eDialogResult == DialogResult.OK)
            {
                this.PrepareListViewForOrdBfrDateReport();

                DatabaseManager oDatabaseManager = new DatabaseManager();
                SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(
                    String.Format(GlobalConstants.SELECT_ORDERS_BEFORE_DATE
                    , oOrdBfrDateDlg.Ord_Bfr_Date_Input.Value.ToString(GlobalConstants.DATE_FORMAT)));

                OrdersBeforeDateResult oOrdersBeforeDateResult = new OrdersBeforeDateResult(oSqlDataReader);
                oSqlDataReader.Close();

                this.FillOrdBfrDateReportData(oOrdersBeforeDateResult.oResultSet);
            }

            oOrdBfrDateDlg.Close();
        }

        private void Admin_Customers_Button_Click(object sender, EventArgs e)
        {
            CustomersFilterDialog oCustomersFilterDialog = new CustomersFilterDialog();
            DialogResult oDlgRes = oCustomersFilterDialog.ShowDialog();

            if (oDlgRes == DialogResult.OK)
            {
                this.PrepareListViewForCustomersReport();

                DatabaseManager oDatabaseManager = new DatabaseManager();
                SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(oCustomersFilterDialog.FormSelectFilterQuery());
                CustomersReader oCustomersReader = new CustomersReader();
                oCustomersReader.Read_Many_Customers(oSqlDataReader);
                oSqlDataReader.Close();

                this.FillCustomersReportData(oCustomersReader.oCustomers);
            }

            oCustomersFilterDialog.Close();
        }

        private void Admin_Drivers_Button_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForDriversReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_DRIVERS_AND_THEIR_NAMES);
            DriversAndNamesReader oDriversAndNamesReader = new DriversAndNamesReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillDriversAndNamesView(oDriversAndNamesReader.oDriversAndNames);
        }

        private void Admin_Cars_Button_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForCarsReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_CARS_AND_OWNERS);
            CarsAndOwnersReader oCarsAndOwnersReader = new CarsAndOwnersReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillCarsAndOnwersView(oCarsAndOwnersReader.oCarsAndOwnersList);
        }

        private void Admin_Orders_Button_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForOrdersReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ORDERS_AND_ADD_DATA);
            OrdersViewModelReader oOrdersViewModelReader = new OrdersViewModelReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillOrdersViewModelsInListView(oOrdersViewModelReader.oOrderViewModels);
        }

        private void Admin_Manufacturers_Button_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForManufacturersReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ALL_MANUFACTURERS);
            ManufacturersReader oManufacturersReader = new ManufacturersReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillManufacturersInListView(oManufacturersReader.oManufacturersList);
        }

        private void Admin_Order_Requests_Button_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForOrdReqCustNamesReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ORDERS_REQUESTS_AND_CUST_NAMES);
            OrdReqCustNameReader oOrdReqCustNameReader = new OrdReqCustNameReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillOrdReqsCustNamesInListView(oOrdReqCustNameReader.oOrdReqCustNamesList);
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        private void ordersBeforeDateToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OrdersBeforeDateDialog oOrdBfrDateDlg = new OrdersBeforeDateDialog();
            DialogResult eDialogResult = oOrdBfrDateDlg.ShowDialog();

            if (eDialogResult == DialogResult.OK)
            {
                this.PrepareListViewForOrdBfrDateReport();

                DatabaseManager oDatabaseManager = new DatabaseManager();
                SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(
                    String.Format(GlobalConstants.SELECT_ORDERS_BEFORE_DATE
                    , oOrdBfrDateDlg.Ord_Bfr_Date_Input.Value.ToString(GlobalConstants.DATE_FORMAT)));

                OrdersBeforeDateResult oOrdersBeforeDateResult = new OrdersBeforeDateResult(oSqlDataReader);
                oSqlDataReader.Close();

                this.FillOrdBfrDateReportData(oOrdersBeforeDateResult.oResultSet);
            }

            oOrdBfrDateDlg.Close();
        }

        private void customersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            CustomersFilterDialog oCustomersFilterDialog = new CustomersFilterDialog();
            DialogResult oDlgRes = oCustomersFilterDialog.ShowDialog();

            if (oDlgRes == DialogResult.OK)
            {
                this.PrepareListViewForCustomersReport();

                DatabaseManager oDatabaseManager = new DatabaseManager();
                SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(oCustomersFilterDialog.FormSelectFilterQuery());
                CustomersReader oCustomersReader = new CustomersReader();
                oCustomersReader.Read_Many_Customers(oSqlDataReader);
                oSqlDataReader.Close();

                this.FillCustomersReportData(oCustomersReader.oCustomers);
            }

            oCustomersFilterDialog.Close();
        }

        private void driversToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForDriversReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_DRIVERS_AND_THEIR_NAMES);
            DriversAndNamesReader oDriversAndNamesReader = new DriversAndNamesReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillDriversAndNamesView(oDriversAndNamesReader.oDriversAndNames);
        }

        private void ordersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForOrdersReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ORDERS_AND_ADD_DATA);
            OrdersViewModelReader oOrdersViewModelReader = new OrdersViewModelReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillOrdersViewModelsInListView(oOrdersViewModelReader.oOrderViewModels);
        }

        private void carsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForCarsReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_CARS_AND_OWNERS);
            CarsAndOwnersReader oCarsAndOwnersReader = new CarsAndOwnersReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillCarsAndOnwersView(oCarsAndOwnersReader.oCarsAndOwnersList);
        }
        
        private void manufacturersToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForManufacturersReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ALL_MANUFACTURERS);
            ManufacturersReader oManufacturersReader = new ManufacturersReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillManufacturersInListView(oManufacturersReader.oManufacturersList);
        }
        private void orderRequestsToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.PrepareListViewForOrdReqCustNamesReport();

            DatabaseManager oDatabaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader = oDatabaseManager.ExecuteQuery(GlobalConstants.SELECT_ORDERS_REQUESTS_AND_CUST_NAMES);
            OrdReqCustNameReader oOrdReqCustNameReader = new OrdReqCustNameReader(oSqlDataReader);
            oSqlDataReader.Close();

            this.FillOrdReqsCustNamesInListView(oOrdReqCustNameReader.oOrdReqCustNamesList);
        }

        private void viewProfileToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // Крием Home страницата
            this.Hide();

            // Показваме Profile страницата
            ProfileDialog oProfileDialog = new ProfileDialog(recCustomer);
            oProfileDialog.ShowDialog();

            // За всеки случай ако е променян потребителят, го взимаме наново от базата
            DatabaseManager oDataBaseManager = new DatabaseManager();
            SqlDataReader oSqlDataReader =
                oDataBaseManager.ExecuteQuery(String.Format(GlobalConstants.SELECT_CUSTOMER_BY_ID, this.recCustomer.nId));

            // Записваме си го при нас
            this.recCustomer = new Customer(oSqlDataReader);
            this.profileToolStripMenuItem.Text = String.Format(GlobalConstants.WELCOME_USER, this.recCustomer.strName);

            // Да не забравим да затворим след нас
            oSqlDataReader.Close();

            // Показваме обратно Home страницата
            this.Show();
        }

        private void logoutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            LogoutPopUp oDlg = new LogoutPopUp();
            DialogResult oDlgResult = oDlg.ShowDialog();
            if(oDlgResult == DialogResult.OK)
            {
                this.DialogResult = DialogResult.Cancel;
                this.Close();
            }
        }

    }

}

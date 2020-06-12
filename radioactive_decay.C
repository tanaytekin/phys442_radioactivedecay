

float sq_x[] = {22.57,45.02,76.42,128.4}; 
float sq_q_err[] = {0.14, 0.14, 0.14, 0.14};
float sq_y[] = {0.05241,0.03874, 0.02703, 0.01493}; 
float sq_y_err[] = {0.00078, 0.00042, 0.00021, 0.0006};



void draw_sq()
{
        TCanvas *canvas = new TCanvas("canvas", "graph_canvas",  1000, 1000);
        canvas->SetLeftMargin(0.15);
        TGraphErrors *graph = new TGraphErrors(4, sq_x, sq_y, NULL, sq_y_err);

        graph->SetTitle("T vs. 1/s for 2.5 kV, 5 squeezes");
        //gStyle->SetOptFit(111);
        graph->GetXaxis()->SetTitle("T[s]");
        graph->GetYaxis()->SetTitle("1/s[s-1]");

        graph->SetLineColor(2);
        graph->SetLineWidth(2);
        graph->SetMarkerColor(4);
        graph->SetMarkerStyle(4);
        graph->SetMarkerSize(1);
        //graph->GetYaxis() -> SetTitleOffset(1.5);
        graph->Draw("AP");
        graph->Print();


        TF1 *fit = new TF1("line_fit", "[0]+[1]*x");
        fit->SetLineColor(1);
        graph->Fit(fit);
        
        TLegend legend;
        legend.AddEntry(graph, "Data points with error bars", "lep");
        legend.DrawClone("Same");



}




void line_fit(const char *data_location, float kv, int sq)
{
        TCanvas *canvas = new TCanvas("canvas", "graph_canvas",  500, 500);
        canvas->SetLeftMargin(0.15);
        TGraphErrors *graph = new TGraphErrors(data_location, "%lg %lg %lg %lg", " ");

        char str[80];
        sprintf(str, "T vs. ln(1/s) for %.1f kV, %d squeezes", kv, sq); 


        graph->SetTitle(str);
        gStyle->SetOptFit(111);
        graph->GetXaxis()->SetTitle("T[s]");
        graph->GetYaxis()->SetTitle("ln(1/s)");

        graph->SetLineColor(2);
        graph->SetLineWidth(2);
        graph->SetMarkerColor(4);
        graph->SetMarkerStyle(4);
        graph->SetMarkerSize(1);
        //graph->GetYaxis() -> SetTitleOffset(1.5);
        graph->Draw("AP");
        graph->Print();


        TF1 *fit = new TF1("line_fit", "[0]+[1]*x");
        fit->SetLineColor(1);
        graph->Fit(fit);
        
        TLegend legend;
        legend.AddEntry(graph, "Data points", "lep");
        legend.AddEntry(fit, "Line Fit");
        legend.DrawClone("Same");

}

void radioactive_decay()
{

}

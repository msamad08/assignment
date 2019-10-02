#ifndef SCHOLARSHIP_H
#define SCHOLARSHIP_H

#include "scholarshipClassDeclared.h"

void createReportHeadings(std::ofstream &fout);
void createReportSummary(std::vector<Scholarship> sArray, std::ofstream &fout);
std::string addCommas(int num);
void OpenFiles(std::ifstream &in, std::ofstream &out);
bool readFile(std::string &sLine, std::vector<std::string> &sParsed, std::ifstream &fin, Scholarship& scholars);
void createReportHeadings(std::ofstream &fout);
void writeFile(Scholarship s, std::ofstream &fout); // Also pass in the output file buffer by ref to write to
void writeFile(Scholarship s, std::ofstream &fout, std::string sType); // Also pass in the output file buffer by ref to write to

#endif // !SCHOLARSHIP_H 

void createReportHeadings(ofstream &fout);
void createReportSummary(vector<Scholarship> sArray, ofstream &fout);
string addCommas(int num);
void OpenFiles(ifstream &in, ofstream &out);
Scholarship readFile(string &sLine, vector<string> &sParsed, ifstream &fin);
void writeFile(Scholarship s,    // Pass in by value- no need to change string in main()
	           ofstream &fout)   // Also pass in the output file buffer by ref to write to
{
	static int lineCount = 60;
	if (lineCount == 60)         // Ready for next page
	{
		fout << endl;       //
		createReportHeadings(fout);
		lineCount = 0;
	}
	fout << s.getID() << right << setw(10) << addCommas(s.getAmount())
		 << "    " << left << setw(12) << s.getType()
		 << setw(10) << s.getLength() << right << setw(10) << s.getDate()
		 << "    " << left << setw(15) << s.getFname() << s.getLname() << endl;
	lineCount++;
}
void createReportHeadings(ofstream &fout);
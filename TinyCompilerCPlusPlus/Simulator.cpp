#include "Simulator.hpp"


int Simulator::simulate(const vector <string>& assembly, const vector <int>& argv) {
	int r0 = 0, r1 = 0;
	stack <int> istack;
	for (auto& ins : assembly) {
		string code = ins.substr(0, 2);
		if (code == "IM") { r0 = stoi(ins.substr(3)); }
		else if (code == "AR") { r0 = argv.at(stoi(ins.substr(3))); }
		else if (code == "SW") { swap(r0, r1); }
		else if (code == "PU") { istack.push(r0); }
		else if (code == "PO") { r0 = istack.top(); istack.pop(); }
		else if (code == "AD") { r0 += r1; }
		else if (code == "SU") { r0 -= r1; }
		else if (code == "MU") { r0 *= r1; }
		else if (code == "DI") { r0 /= r1; }
	}
	return r0;
}
#include <iostream>
#include <string>
#include <cstdio>
const std::string foo = "AIcCAYWcSeMISeCCEUOUQCKGKIYWEUeEAKKAIeeEeeACYQUFbPLTRcDPNBXNBPBJHLLTPXDdTHVZGAFZdQbDbLeWBTTRPXAIKfZVWecfTNCbCKfOXFXUQFXcXLOIKNUPVcWFLVVZTEAKJdPTa";
const long long   bar = 88767;

long long s = 0;
long long n() { return s=(s*1664525+1013904223)%(1LL<<32); }

int g(long long b) {
    for (long long i=0;;++i) { 
        char c = i<145 ? foo[i] : "HeHeHe"[i%6];
        int x = c - 65 - 6*(c>90);
        for (int j=0; j+x%2<2; ++j)
			for (int q=0; q<2; ++q)
				if (!b--) return
	(((bar<<8)+228)>>(2*((x>>(2*j+1))&(3+12*(x%2)))+1-q))&1;
    }
}

int main() {
    double x=0, y=0;
    while (true) {
        for (int i=0; i<1000; ++i)
			{
				fprintf(stderr,"boo\n");
				long long b=n();
				if (!g(b)) x=(b%21+x)/21, y=(20-b/21+y)/21;
			}
        std::cout << x << " " << y << "\n";
    }
}

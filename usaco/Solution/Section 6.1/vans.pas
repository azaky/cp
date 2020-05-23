{
ID: a_zaky01
PROG: vans
LANG: PASCAL
}

const
  mapchr:array['0'..'9'] of longint = (0,1,2,3,4,5,6,7,8,9);
  mapnum:array[-1..9] of char = ('?','0','1','2','3','4','5','6','7','8','9');

Var
  n,i:longint;
  ans:array[0..1005] of ansistring;
  
function sum(a,b:ansistring):ansistring;
  var
    na,nb,borrow,t,i:longint;
  
  begin
    if a='0' then exit(b) else if b='0' then exit(a);
    na:=length(a); nb:=length(b);
    if na<nb then exit(sum(b,a));
    borrow:=0; sum:='';
    for i:=1 to na do
      begin
        if i>nb then t:=mapchr[a[na+1-i]]+borrow
          else t:=mapchr[a[na+1-i]]+mapchr[b[nb+1-i]]+borrow;
        borrow:=t div 10; sum:=mapnum[t mod 10]+sum;
      end;
    if borrow>0 then sum:=mapnum[borrow]+sum;
  end;

function sub(a,b:ansistring):ansistring;
  var
    na,nb,i,t:longint;
  
  begin
    na:=length(a); nb:=length(b); sub:='';
    for i:=1 to na do
      begin
        if a[na+1-i]='?' then
          begin
            a[na-i]:=mapnum[mapchr[a[na-i]]-1];
            if i>nb then t:=9 else t:=9-mapchr[b[nb+1-i]];
          end
        else if i>nb then t:=mapchr[a[na+1-i]]
          else t:=mapchr[a[na+1-i]]-mapchr[b[nb+1-i]];
        if t<0 then
          begin
            a[na-i]:=mapnum[mapchr[a[na-i]]-1];
            t:=t+10;
          end;
        sub:=mapnum[t]+sub;
      end;
  end;

Begin
    Assign(input, 'vans.in'); Reset(input);
    Assign(output, 'vans.out'); Rewrite(output);
	readln(n);
	ans[1]:='0'; ans[2]:='2'; ans[3]:='4'; ans[4]:='12';
	{
		* it can be proved that ans[n]:=2*ans[n-1]+2*ans[n-2]-2*ans[n-3]+ans[n-4]
	}
	for i:=5 to n do
	  begin
	    ans[i]:='0';
	    ans[i]:=sum(ans[i],sum(ans[i-1],ans[i-1]));
	    ans[i]:=sum(ans[i],sum(ans[i-2],ans[i-2]));
	    ans[i]:=sum(ans[i],ans[i-4]);
	    ans[i]:=sub(ans[i],sum(ans[i-3],ans[i-3]));
	  end;
	writeln(ans[n]);
    Close(input); Close(output);
End.

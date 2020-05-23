const
  ten :array[0..9] of int64 = (1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000);
  ll = 1022;
  
var
  nlucky,i,j,k,a,b,la,lb,pl,pr,vl,vr:longint;
  ans,num,l,r:int64;
  prob:extended;
  lucky:array[0..ll+1] of int64;

function max(a,b:longint):longint;
  begin
    if a<b then exit(b) else exit(a);
  end;

function min(a,b:longint):longint;
  begin
    if a<b then exit(a) else exit(b);
  end;

begin
  nlucky:=0;
  for i:=1 to 9 do
    begin
	  for j:=0 to (1 shl i)-1 do
	    begin
		  num:=0;
		  for k:=i downto 1 do
		    if j and (1 shl (k-1))=0 then num:=num+4*ten[k-1]
			  else num:=num+7*ten[k-1];
		  inc(nlucky); lucky[nlucky]:=num;
		end;
	end;
  //for i:=1 to ll do writeln(lucky[i]);
  lucky[0]:=0; lucky[ll+1]:=maxlongint;
  readln(pl,pr,vl,vr,k); ans:=0;
  for i:=1 to ll-k+1 do
    begin
	  a:=lucky[i]; b:=lucky[i+k-1];
	  la:=lucky[i-1]; lb:=lucky[i+k];
	  
	  if (pl<=a) and (a<=pr) then l:=int64(min(pr,a)-max(pl-1,la))
	    else if (la<pr) and (pr<=a) then l:=int64(pr-max(pl-1,la))
		  else l:=0;
	  if (vl<=b) and (b<=vr) then r:=int64(min(vr+1,lb)-max(vl,b))
	    else if (b<=vl) and (vl<lb) then r:=int64(min(vr+1,lb)-vl)
		  else r:=0;
	  ans:=ans+r*l;
	  
	  if (vl<=a) and (a<=vr) then l:=int64(min(vr,a)-max(vl-1,la))
	    else if (la<vr) and (vr<=a) then l:=int64(vr-max(vl-1,la))
		  else l:=0;
	  if (pl<=b) and (b<=pr) then r:=int64(min(pr+1,lb)-max(pl,b))
	    else if (b<=pl) and (pl<lb) then r:=int64(min(pr+1,lb)-pl)
		  else r:=0;
	  ans:=ans+r*l;
	  
	  if (pl=vl)and(vl=vr)and(pr=vr)and(pl=a) then dec(ans);
	end;
  //writeln(ans);
  prob:=(ans/((pr-pl+1))/(vr-vl+1)); writeln(prob:0:15);
end.

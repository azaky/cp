const
  maxn = 10000;

var
  n,k,i,j,a,sum,t,b,add:longint;
  best:extended;
  allnegative,allpositive:boolean;
  num,neg,pos,neg2,pos2:array[0..maxn] of longint;
  
begin
  while true do
    begin
	  read(n,k); if (n=0) and (k=0) then break;
	  allnegative:=true; allpositive:=true;
	  fillchar(num,sizeof(num),0);
	  fillchar(neg,sizeof(neg),0);
	  
	  for i:=1 to n do
	    begin
		  read(a); if a<0 then inc(num[-a]) else inc(num[a]);
		  if a<0 then
		    begin
			  inc(neg[-a]);
			  allpositive:=false;
			end
		  else if a>0 then allnegative:=false;
		end;
	  
	  if allnegative and (k mod 2=1) then
	    begin
		  dec(k,num[0]); sum:=0;
		  for i:=1 to maxn do
		    begin
			  if num[i]=0 then continue
			    else if k=0 then break;
			  if k>num[i] then
			    begin
				  dec(k,num[i]);
				  sum:=sum+i*num[i];
				end
			  else
			    begin
				  sum:=sum+k*i;
				  break;
				end;
			end;
		  writeln(-sum); continue;
		end
	  else if allpositive then
	    begin
		  sum:=0;
		  for i:=maxn downto 0 do
		    begin
			  if num[i]=0 then continue
			    else if k=0 then break;
			  if k>num[i] then
			    begin
				  dec(k,num[i]);
				  sum:=sum+i*num[i];
				end
			  else
			    begin
				  sum:=sum+k*i;
				  break;
				end;
			end;
		  writeln(sum); continue;
		end;
	  
	  for i:=1 to maxn do pos[i]:=num[i]-neg[i];
	  
	  if num[0]+k=n then
	    begin
		  t:=0; for i:=1 to maxn do inc(t,neg[i]);
		  if t mod 2=0 then
		    begin
			  sum:=0;
			  for i:=1 to maxn do sum:=sum+i*(pos[i]-neg[i]);
			  writeln(sum); continue;
			end
		  else
		    begin
			  sum:=0;
			  for i:=maxn downto 1 do
			    begin
			      sum:=sum+i*pos[i];
				  if num[0]>neg[i] then dec(num[i],neg[i])
				    else
				      begin
					    dec(neg[i],num[0]); sum:=sum-i*neg[i];
					  end;
			    end;
			  writeln(sum); continue;
			end;
		end
	  else if num[0]+k>n then
	    begin
		  sum:=0;
		  for i:=maxn downto 1 do
		    begin
			  if pos[i]=0 then continue
			    else if k=0 then break;
			  if k>pos[i] then
			    begin
				  dec(k,pos[i]);
				  sum:=sum+i*pos[i];
				end
			  else
			    begin
				  sum:=sum+i*k;
				  break;
				end;
			end;
		  dec(k,num[0]);
		  if k>0 then
		    for i:=1 to maxn do
			  begin
			    if neg[i]=0 then continue
				  else if k=0 then break;
				if k>neg[i] then
				  begin
				    dec(k,neg[i]);
					sum:=sum-i*neg[i];
				  end
				else
				  begin
				    sum:=sum-i*k;
					break;
				  end;
			  end;
		  writeln(sum); continue;
		end
	  else if num[0]+k<n then
	    begin
		  fillchar(pos2,sizeof(pos2),0);
		  fillchar(neg2,sizeof(neg2),0);
		  sum:=0; t:=0;
		  for i:=maxn downto 1 do
		    begin
			  if num[i]=0 then continue
			    else if k=0 then break;
			  if k>pos[i] then
			    begin
				  dec(k,pos[i]); pos2[i]:=pos[i]; pos[i]:=0;
				  sum:=sum+i*pos2[i];
				end
			  else
			    begin
				  pos2[i]:=k; dec(pos[i],k);
				  sum:=sum+i*k; k:=0;
				  break;
				end;
			  if k=0 then break;
			  if k>neg[i] then
			    begin
				  inc(t,neg[i]); dec(k,neg[i]); neg2[i]:=neg[i]; neg[i]:=9;
				  sum:=sum-i*neg2[i];
				end
			  else
			    begin
				  neg2[i]:=k; dec(neg[i],k); inc(t,k);
				  sum:=sum-i*k; k:=0;
				  break;
				end;
			end;
		  //writeln(sum,' ',t);
		  if t mod 2=0 then
		    begin
			  writeln(sum); continue;
			end;
		  best:=0; add:=-100000001;
		  a:=i; b:=i;
		  while (pos2[b]=0) and (neg2[b]=0) do inc(b);
		  while (pos[a]=0) and (neg[a]=0) do dec(a);
		  //writeln(a,' ',b);
		  for i:=b to maxn do
		  begin
		    if a/i<best then break;
		    for j:=a downto 1 do
			  begin
			    if ((pos2[i]=0) or (neg[j]=0)) and ((neg2[i]=0) or (pos[j]=0)) then continue
				  else if j/i<best then break;
				//writeln(i,' ',j,' ',pos2[i],' ',neg2[i]);
				if (pos2[i]>0) and (neg[j]>0) then
				  begin
				    if j/i>best then
					  begin
					    best:=j/i; add:=-i-j;
					  end
					else if j/i=best then
					  begin
					    if -i-j>add then add:=-i-j;
					  end;
				  end;
				if (neg2[i]>0) and (pos[j]>0) then
				  begin
				    if j/i>best then
					  begin
					    best:=j/i; add:=i+j;
					  end
					else if j/i=best then
					  begin
					    if i+j>add then add:=i+j;
					  end;
				  end;
			  end;
		  end;
		  //writeln(best:0:2,' ',add);
		  writeln(sum+add); continue;
		end
	end;
end.
type
  tipe=record
         sum:int64;
         k:integer;
       end;

var
  r,c,i,j,r0,c0,max:longint;
  ch:char;
  obs:array[0..51,0..51] of boolean;
  tl,tr:array[0..51] of extended;
  t:array[0..51,0..51] of extended;
  fl,fr:array[0..51] of tipe;
  f:array[0..51,0..51] of tipe;
  p:array[0..60] of int64;
  ob:tipe;
  
begin
  fillchar(obs,sizeof(obs),true);
  
  readln(r,c);
  for i:=1 to r do
    begin
      for j:=1 to c do
        begin
          read(ch);
          if ch<>'X' then
            begin
              obs[i,j]:=false;
              if ch='B' then
                begin
                  r0:=i; c0:=j;
                end;
            end;
        end;
      readln;
    end;
  
  p[0]:=1;
  for i:=1 to 60 do p[i]:=2*p[i-1];
  
  with ob do
    begin
      sum:=-1; k:=0;
    end;
  
  for i:=r downto r0 do
    begin
      for j:=0 to c do
        if obs[i,j] then fl[j]:=ob
          else if obs[i+1,j] then
            begin
              fl[j].sum:=fl[j-1].sum+p[fl[j-1].k];
              fl[j].k:=fl[j-1].k;
            end
          else
            begin
              fl[j].sum:=f[i+1,j].sum+p[f[i+1,j].k];
              fl[j].k:=f[i+1,j].k;
            end;
      for j:=c+1 downto 1 do
        if obs[i,j] then fr[j]:=ob
          else if obs[i+1,j] then
            begin
              fr[j].sum:=fr[j+1].sum+p[fr[j+1].k];
              fr[j].k:=fr[j+1].k;
            end
          else
            begin
              fr[j].sum:=f[i+1,j].sum+p[f[i+1,j].k];
              fr[j].k:=f[i+1,j].k;
            end;
      for j:=1 to c do
        if not obs[i+1,j] then
          begin
            f[i,j].sum:=f[i+1,j].sum+p[f[i+1,j].k];
            f[i,j].k:=f[i+1,j].k;
          end
        else
          begin
            if fl[j].k>fr[j].k then max:=fl[j].k
              else max:=fr[j].k;
            f[i,j].sum:=fl[j].sum*p[max-fl[j].k]+fr[j].sum*p[max-fr[j].k];
            f[i,j].k:=max+1;
          end;
    end;
  
  with f[r0,c0] do writeln(sum/p[k]:0:3);
    
  {
  for i:=r downto r0 do
    begin
      tl[0]:=-1.00; tr[c+1]:=-1.00;
      for j:=1 to c do
        if obs[i,j] then tl[j]:=-1.00
          else if obs[i+1,j] then tl[j]:=tl[j-1]+1.00
            else tl[j]:=t[i+1,j]+1.00;
      for j:=c downto 1 do
        if obs[i,j] then tr[j]:=-1.00
          else if obs[i+1,j] then tr[j]:=tr[j+1]+1.00
            else tr[j]:=t[i+1,j]+1.00;
      for j:=1 to c do
        if not obs[i+1,j] then t[i,j]:=t[i+1,j]+1.00
          else t[i,j]:=(tl[j]+tr[j])/2;
    end;
  
  writeln(t[r0,c0]:0:3);
  }
  
end.

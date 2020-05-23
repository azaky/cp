{
ID: a_zaky01
PROG: prime3
LANG: PASCAL
}

type
  data=array[0..6] of longint;
  square=array[1..5,1..5] of integer;

const
  max=99999;
  maxp=1000;
  p:data=(1,10,100,1000,10000,100000,100000);
  valid:array[0..9] of boolean=(false,true,false,true,false,false,false,true,false,true);

var
  n,i,j,k,sum,temp,totalans:longint;
  i11,i12,i13,i14,i15,i21,i22,i23,i24,i25,i31,i32,i33,i34,i35,i41,i42,i43,i44,i45,i51,i52,i53,i54,i55:integer;
  a:square;
  ans:array[1..maxp] of square;

  arr:array[1..max] of boolean;
  prime:array[1..9,0..9,0..9,0..9,0..9] of boolean;
  existf,existt:array[0..max] of boolean;

  fin,fout:text;

label
  closefile;

procedure sieve;
  var
    pi,k,i,j,temp,sum0,a1,a2,a3,a4,a5:longint;

  begin
    arr[1]:=true;
    pi:=2;
    while pi<=trunc(sqrt(max)) do
      begin
        while arr[pi] do inc(pi);
        for k:=2 to max div pi do
          arr[pi*k]:=true;
        inc(pi);
      end;
    for k:=10001 to max do
      if not arr[k] then
        begin
          temp:=k;
          sum0:=0;
          while temp>0 do
            begin
              inc(sum0,temp mod 10);
              temp:=temp div 10;
            end;
          if sum0=sum then
            begin
              temp:=k;
              a5:=temp mod 10;
              temp:=temp div 10;
              a4:=temp mod 10;
              temp:=temp div 10;
              a3:=temp mod 10;
              temp:=temp div 10;
              a2:=temp mod 10;
              temp:=temp div 10;
              a1:=temp mod 10;
              prime[a1,a2,a3,a4,a5]:=true;
            end;
        end;
  end;

procedure sort(l,r:longint);
  var
    i,j:longint;
    mid,temp:square;

  function less(a1,a2:square):boolean;
    var
      i,j:integer;

    begin
      for i:=1 to 5 do
        for j:=1 to 5 do
          if a1[i,j]<a2[i,j] then exit(true)
            else if a1[i,j]>a2[i,j] then exit(false);
      exit(false);
    end;

  begin
    i:=l;
    j:=r;
    mid:=ans[(l+r) div 2];
    repeat
      while less(ans[i],mid) do inc(i);
      while less(mid,ans[j]) do dec(j);
      if i<=j then
        begin
          temp:=ans[i];
          ans[i]:=ans[j];
          ans[j]:=temp;
          inc(i);
          dec(j);
        end;
    until i>j;
    if l<j then sort(l,j);
    if i<r then sort(i,r);
  end;

begin
  assign(fin,'prime3.in');
  assign(fout,'prime3.out');
  reset(fin);
  rewrite(fout);

  readln(fin,sum,i11);
  sieve;

  totalans:=0;
  for i22:=0 to 9 do
   for i33:=0 to 9 do
    for i55:=1 to 9 do
     if valid[i55] and (i11+i22+i33+i55<=sum) then
      begin
       i44:=sum-i11-i22-i33-i55;
       if i44<10 then
        if prime[i11,i22,i33,i44,i55] then
         for i51:=1 to 9 do
          if valid[i51] then
           for i42:=0 to 9 do
            for i15:=1 to 9 do
             if valid[i15] and (i51+i42+i33+i15<=sum) then
              begin
               i24:=sum-i51-i42-i33-i15;
               if i24<10 then
                if prime[i51,i42,i33,i24,i15] then
                 for i12:=1 to 9 do
                  for i13:=1 to 9 do
                   if (i11+i12+i13+i15<sum) then
                    begin
                     i14:=sum-i11-i12-i13-i15;
                     if i14<10 then
                      if prime[i11,i12,i13,i14,i15] then
                       for i52:=1 to 9 do
                        if valid[i52] and (i12+i22+i42+i52<=sum) then
                         begin
                          i32:=sum-i12-i22-i42-i52;
                          if i32<10 then
                           if prime[i12,i22,i32,i42,i52] then
                            for i54:=1 to 9 do
                             if valid[i54] and
                                (i14+i24+i44+i54<=sum) and
                                (i51+i52+i54+i55<=sum) then
                              begin
                               i34:=sum-i14-i24-i44-i54;
                               i53:=sum-i51-i52-i54-i55;
                               if (i34<10) and (i53<10) then
                                if prime[i14,i24,i34,i44,i54] and prime[i51,i52,i53,i54,i55] then
                                 for i23:=0 to 9 do
                                  if (i13+i23+i33+i53<=sum) then
                                   begin
                                    i43:=sum-i13-i23-i33-i53;
                                    if i43<10 then
                                     if prime[i13,i23,i33,i43,i53] then
                                      for i25:=1 to 9 do
                                       if valid[i25] and (i22+i23+i24+i25<sum) then
                                        begin
                                         i21:=sum-i22-i23-i24-i25;
                                         if i21<10 then
                                          if prime[i21,i22,i23,i24,i25] then
                                           for i35:=1 to 9 do
                                            if valid[i35] then
                                             begin
                                              i45:=sum-i15-i25-i35-i55;
                                              i41:=sum-i42-i43-i44-i45;
                                              i31:=sum-i11-i21-i41-i51;
                                              if (i45>0) and (i45<10) and
                                                 (i41>0) and (i41<10) and
                                                 (i31>0) and (i31<10) then
                                               if prime[i11,i21,i31,i41,i51] and
                                                  prime[i15,i25,i35,i45,i55] and
                                                  prime[i31,i32,i33,i34,i35] and
                                                  prime[i41,i42,i43,i44,i45] then
                                                begin
                                                 inc(totalans);
                                                 a[1,1]:=i11; a[1,2]:=i12; a[1,3]:=i13; a[1,4]:=i14; a[1,5]:=i15;
                                                 a[2,1]:=i21; a[2,2]:=i22; a[2,3]:=i23; a[2,4]:=i24; a[2,5]:=i25;
                                                 a[3,1]:=i31; a[3,2]:=i32; a[3,3]:=i33; a[3,4]:=i34; a[3,5]:=i35;
                                                 a[4,1]:=i41; a[4,2]:=i42; a[4,3]:=i43; a[4,4]:=i44; a[4,5]:=i45;
                                                 a[5,1]:=i51; a[5,2]:=i52; a[5,3]:=i53; a[5,4]:=i54; a[5,5]:=i55;
                                                 ans[totalans]:=a;
                                                end;
                                             end;
                                        end;
                                   end;
                              end;
                         end;
                    end;
              end;
      end;

  if totalans>0 then
    begin
      sort(1,totalans);
      for k:=1 to totalans do
        begin
          for i:=1 to 5 do
            begin
              for j:=1 to 5 do write(fout,ans[k][i,j]);
              writeln(fout);
            end;
          if k<totalans then writeln(fout);
        end;
    end
  else writeln(fout,'NONE');

  closefile:
  close(fin);
  close(fout);
end.
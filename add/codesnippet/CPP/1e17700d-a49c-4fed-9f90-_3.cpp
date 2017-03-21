   static void Read_Callback( IAsyncResult^ ar )
   {
      StateObject^ so = safe_cast<StateObject^>(ar->AsyncState);
      Socket^ s = so->workSocket;

      int read = s->EndReceive( ar );

      if ( read > 0 )
      {
         so->sb->Append( Encoding::ASCII->GetString( so->buffer, 0, read ) );
         s->BeginReceive( so->buffer, 0, StateObject::BUFFER_SIZE, SocketFlags::None,
            gcnew AsyncCallback( &Async_Send_Receive::Read_Callback ), so );
      }
      else
      {
         if ( so->sb->Length > 1 )
         {
            //All of the data has been read, so displays it to the console
            String^ strContent = so->sb->ToString();
            Console::WriteLine( String::Format( "Read {0} byte from socket" +
               " data = {1} ", strContent->Length, strContent ) );
         }
         s->Close();
      }
   }
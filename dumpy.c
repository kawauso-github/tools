#include <stdio.h>

void dumpy( unsigned char*, unsigned char*, unsigned long );


#if 1
void main()
{
	unsigned int	index = 0;
	unsigned char	data[ 512 ];

	for( index = 0 ; index <= ( 0x3f - 0x20 ) ; index++ )
	{
		data[ index ] = ( index + 0x20 );
	}

	dumpy( "test dump", data , 24 );

	return;
}
#endif

void dumpy( unsigned char *titole, unsigned char *data, unsigned long length )
{
	unsigned int	line = 0;
	unsigned int	line_index = 0;
	unsigned int	index = 0;
	unsigned int	save = 0;

	/* 何行出力するか算出する */
	line = length / 16;

	if( ( length % 16 ) != 0 ) {
		line++;
	}

	/* タイトルを表示する */
	printf( "##### %s #####\n", titole );
	printf( "# address # 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F #     ascii      #\n" );

	/* 出力行数分繰り返す */
	for ( line_index = 0 ; line_index < line ; line_index++ )
	{
		printf( "  %0.8x  ", &data[ index ] );

		save = ( line_index * 16 );

		for ( index = save ; index < ( ( line_index + 1 ) * 16 ) ; index++ )
		{
			if( index < length )
			{
				printf( "%0.2x ", data[ index ] );
			}
			else {
				printf( "   " );
			}
		}

		printf( " " );

		for ( index = save ; index < ( ( line_index + 1 ) * 16 ) ; index++ )
		{
			if( index < length )
			{
				if( ( data[ index ] >= 0x20 ) && ( data[ index ] <= 0x7e ) ) {

					printf( "%1.1c", data[ index ] );
				}
				else {

					printf( "." );
				}
			}
		}

		printf( "\n" );
	}

	return;
}

